//
// Created by admin on 25-5-10.
//

#include "utils.hpp"


boost::property_tree::ptree read_config_from_json()
{
    boost::property_tree::ptree pt;
    // std::ifstream gbkFile("./config.json", std::ios::binary);
    // std::stringstream buffer;
    // buffer << gbkFile.rdbuf();
    // std::string gbkContent = buffer.str();
    // gbkFile.close();
    // std::string utf8Content = GBKToUTF8(gbkContent);
    //
    // std::istringstream iss(utf8Content);

    // read_json(iss, pt);
    try
    {
        read_json("config.json", pt);
    }
    catch (std::exception& e)
    {
        std::cout << e.what();
    }

    return pt;
}

argparse::ArgumentParser read_config_from_cmd(int argc, const char* argv[])
{
    argparse::ArgumentParser program(argc, argv);
    program.add_argument("-p", "--port").default_value(8889).help("port");
    program.print_help();
    return program;
}
