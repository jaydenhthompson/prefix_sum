#include "prefix_sum.h"
#include "helpers.h"
#include "spin_barrier.h"

#include <sstream>
#include <mutex>
#include <pthread.h>

//pthread_barrier_t barrier;
spin_barrier *barrier;

void init(int num_threads)
{
    //pthread_barrier_init(&barrier, nullptr, num_threads);
    barrier = new spin_barrier(num_threads);
}

void compute_prefix_sum(prefix_sum_args_t &a)
{
    int step = 1;
    while (step < a.n_vals)
    {
        int idx = a.t_id;
        while (idx + step < a.n_vals)
        {
            a.output_values->at(idx + step) = a.input_values->at(idx) + a.input_values->at(idx + step);
            idx += a.n_threads;
        }
        step *= 2;
        std::swap(a.output_values, a.input_values);
        //pthread_barrier_wait(&barrier);
        barrier->wait_for_all();
    }
}
