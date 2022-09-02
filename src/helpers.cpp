#include "helpers.h"

int next_power_of_two(int x)
{
    int pow = 1;
    while (pow < x)
    {
        pow *= 2;
    }
    return pow;
}

void fill_args(std::vector<prefix_sum_args_t> &args,
               int n_threads,
               int n_vals,
               std::vector<int> *input_values,
               std::vector<int> *output_values,
               bool spin,
               std::function<int(int, int, int)> op,
               int n_loops)
{
    for (int i = 0; i < n_threads; ++i)
    {
        args[i] = {spin, n_vals, input_values, output_values, n_threads, i, op, n_loops};
    }
}