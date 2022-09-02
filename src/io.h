#ifndef _IO_H
#define _IO_H

#include <argparse.h>
#include <prefix_sum.h>
#include <iostream>
#include <fstream>
#include <vector>

#include "helpers.h"

void read_file(options_t &args,
               int &n_vals,
               std::vector<int> &input_vals,
               std::vector<int> &output_vals);

void write_file(const options_t &args,
                const prefix_sum_args_t &opts);

#endif
