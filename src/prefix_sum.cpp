#include "prefix_sum.h"
#include "helpers.h"

#include <sstream>
#include <mutex>

std::mutex m;

void compute_prefix_sum(prefix_sum_args_t &a)
{
    std::stringstream ss;
    ss << "HI" << a.t_id << std::endl;
    std::cout << ss.str();
}
