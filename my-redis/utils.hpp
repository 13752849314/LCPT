//
// Created by admin on 25-5-10.
//

#ifndef UTILS_H
#define UTILS_H
#include "argparse.hpp"
#include "json.hpp"
using json = nlohmann::json;

json read_config_from_json();

argparse::ArgumentParser read_config_from_cmd(int argc, const char* argv[]);

#endif //UTILS_H
