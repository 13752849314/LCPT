//
// Created by admin on 25-5-10.
//

#include "utils.hpp"

json read_config_from_json()
{
    std::ifstream file("../config.json");
    json j;
    if (!file.is_open())
    {
        std::cout << "file open fail!" << std::endl;
        j["error"] = "file open fail!";
        return j;
    }
    file >> j;
    file.close();
    return j;
}

argparse::ArgumentParser read_config_from_cmd(int argc, const char* argv[])
{
    argparse::ArgumentParser program(argc, argv);
    program.add_argument("-p", "--port").default_value(8889).help("port");
    program.print_help();
    return program;
}
