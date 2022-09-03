#ifndef _SPIN_BARRIER_H
#define _SPIN_BARRIER_H

#include <pthread.h>
#include <iostream>
#include <atomic>
#include <mutex>

class spin_barrier
{
public:
    spin_barrier(int num_threads) : n_threads(num_threads), counter(0) {}

    void wait_for_all();

private:
    const int n_threads;
    std::atomic<int> counter;
    std::atomic<bool> go;
    std::mutex mtx;
};

#endif
