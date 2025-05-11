cmake_minimum_required(VERSION 3.22)
project(my_redis)

set(CMAKE_CXX_STANDARD 11)

add_executable(my_redis main.cpp
        Session.cpp
        Session.hpp
        Server.hpp
        argparse.hpp
        json.hpp
        utils.cpp
        utils.hpp
        Config.hpp
        Command.cpp
        Command.hpp)
