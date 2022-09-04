#pragma once

#include <stdlib.h>
#include <pthread.h>
#include <spin_barrier.h>
#include <iostream>

#include "helpers.h"


void init(int num_vals);

void compute_prefix_sum(prefix_sum_args_t &a);
