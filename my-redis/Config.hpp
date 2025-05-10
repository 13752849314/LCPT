//
// Created by admin on 25-5-10.
//

#ifndef CONFIG_H
#define CONFIG_H
#include <string>
#include <unordered_map>
#include <boost/any.hpp>

#include"utils.hpp"

namespace config
{
    std::unordered_map<std::string, boost::any> Config;

    void initConfigFromJson()
    {
        auto pt = read_config_from_json();
        if (pt.count("port") != 0)
        {
            Config["port"] = pt.get<short>("port");
        }
    }

    void initConfigFromCmd(int argc, const char* argv[])
    {
        initConfigFromJson();
        auto cmd = read_config_from_cmd(argc, argv);
        auto const args = cmd.parse_args();
        Config["port"] = args.get<short>("port");
    }
}

#endif //CONFIG_H
