#pragma once

#include <stdlib.h>
#include <pthread.h>
#include <spin_barrier.h>
#include <vector>
#include <functional>

#include "operators.h"

struct prefix_sum_args_t
{
  std::vector<int> input_vals;
  std::vector<int> output_vals;
  bool spin;
  int n_vals;
  int n_threads;
  int t_id;
  std::function<int(int, int, int)> op;
  int n_loops;
};

int next_power_of_two(int x);

void fill_args(std::vector<prefix_sum_args_t> &args,
               int n_threads,
               int n_vals,
               std::vector<int> &inputs,
               std::vector<int> &outputs,
               bool spin,
               std::function<int(int, int, int)> op,
               int n_loops);
