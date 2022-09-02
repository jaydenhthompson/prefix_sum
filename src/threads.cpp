#include <functional>

#include "helpers.h"

void start_threads(std::vector<std::thread> &threads,
                   std::vector<prefix_sum_args_t> &args,
                   std::function<void(prefix_sum_args_t)> start_routine)
{
  for (size_t i = 0; i < threads.size(); i++)
  {
    threads[i] = std::thread([&]()
                             { start_routine(args[i]); });
  }
}

void join_threads(std::vector<std::thread> &threads)
{
  for (auto &e : threads)
  {
    e.join();
  }
}
