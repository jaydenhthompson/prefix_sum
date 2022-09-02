#pragma once

#include <stdlib.h>
#include <pthread.h>
#include <spin_barrier.h>
#include <vector>
#include <functional>

#include "operators.h"

struct prefix_sum_args_t
{
  bool spin;
  int n_vals;
  std::vector<int> *input_values;
  std::vector<int> *output_values;
  int n_threads;
  int t_id;
  std::function<int(int, int, int)> op;
  int n_loops;
};

int next_power_of_two(int x);

void fill_args(std::vector<prefix_sum_args_t> &args,
               int n_threads,
               int n_vals,
               std::vector<int> *input_values,
               std::vector<int> *output_values,
               bool spin,
               std::function<int(int, int, int)> op,
               int n_loops);
