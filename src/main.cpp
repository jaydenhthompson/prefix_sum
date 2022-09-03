#include <iostream>
#include <chrono>
#include <cstring>
#include <thread>
#include <memory>
#include <vector>

#include "argparse.h"
#include "io.h"
#include "operators.h"
#include "helpers.h"
#include "prefix_sum.h"
#include "threads.h"

using namespace std;

int main(int argc, char **argv)
{
    // Parse args
    options_t opts;
    get_opts(argc, argv, opts);

    bool sequential = false;
    if (opts.n_threads == 0)
    {
        opts.n_threads = 1;
        sequential = true;
    }

    // Setup threads
    std::vector<std::thread> threads(opts.n_threads);

    // Setup args & read input data
    std::vector<prefix_sum_args_t> ps_args(opts.n_threads);
    int n_vals;
    std::vector<int> input_vals, output_vals;
    read_file(opts, n_vals, input_vals, output_vals);

    //"op" is the operator you have to use, but you can use "add" to test
    int (*scan_operator)(int, int, int);
    scan_operator = op;
    // scan_operator = add;

    fill_args(ps_args, opts.n_threads, n_vals, &input_vals, &output_vals, opts.spin, scan_operator, opts.n_loops);

    // Start timer
    auto start = std::chrono::high_resolution_clock::now();

    if (sequential)
    {
        // sequential prefix scan
        output_vals[0] = input_vals[0];
        for (int i = 1; i < n_vals; ++i)
        {
            // y_i = y_{i-1}  <op>  x_i
            ps_args[0].output_values->at(i) = scan_operator(output_vals[i - 1], input_vals[i], opts.n_loops);
        }
    }
    else
    {
        init(opts.n_threads);
        start_threads(threads, ps_args, compute_prefix_sum);

        // Wait for threads to finish
        join_threads(threads);
    }

    // End timer and print out elapsed
    auto end = std::chrono::high_resolution_clock::now();
    auto diff = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << "time: " << diff.count() << std::endl;

    // Write output data
    if (output_vals[n_vals - 1] > input_vals[n_vals - 1])
        write_file(opts, output_vals);
    else
        write_file(opts, input_vals);
}
