#include "prefix_sum.h"
#include "helpers.h"
#include "spin_barrier.h"

#include <sstream>
#include <mutex>
#include <vector>
#include <list>
#include <pthread.h>

spin_barrier *barrier;

void init(int num_threads)
{
    barrier = new spin_barrier(num_threads);
}

void compute_prefix_sum(prefix_sum_args_t &a)
{
    int offset = 0;
    int stride = 1;
    while (stride <= a.n_vals/2)
    {
        int idx = a.t_id;
        while (idx + stride < a.n_vals)
        {
            if(idx + 1 >= stride && ((idx - offset) % (stride * 2)) == 0)
            {
                a.output_values->at(idx + stride) += a.output_values->at(idx);
            }
            idx += a.n_threads;
        }
        offset += stride;
        stride *= 2;
        barrier->wait_for_all();
    }

    stride /= 2;
    while (stride > 0)
    {
        int idx = a.t_id;
        while (idx + stride < a.n_vals)
        {
            if(idx + 1 >= stride && ((idx - offset) % (stride * 2)) == 0)
            {
                a.output_values->at(idx + stride) += a.output_values->at(idx);
            }
            idx += a.n_threads;
        }
        offset -= stride;
        stride /= 2;
        barrier->wait_for_all();
    }
}
