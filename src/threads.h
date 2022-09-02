#ifndef _THREADS_H
#define _THREADS_H

#include <pthread.h>
#include <stdlib.h>
#include <iostream>
#include <prefix_sum.h>
#include <memory>
#include <thread>
#include <vector>
#include "helpers.h"

void start_threads(std::vector<std::thread> &threads,
                   std::vector<prefix_sum_args_t> &args,
                   std::function<void(prefix_sum_args_t)>);

void join_threads(std::vector<std::thread> &threads);

#endif
