//
// Created by admin on 25-5-10.
//

#ifndef UTILS_H
#define UTILS_H
#include <boost/property_tree/ptree.hpp>
#include<boost/property_tree/json_parser.hpp>

#include"argparse.hpp"

boost::property_tree::ptree read_config_from_json();

argparse::ArgumentParser read_config_from_cmd(int argc, const char* argv[]);

#endif //UTILS_H
