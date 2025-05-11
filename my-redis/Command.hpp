//
// Created by admin on 25-5-11.
//

#ifndef COMMAND_HPP
#define COMMAND_HPP
#include <string>
#include <unordered_map>

#include "json.hpp"

class Results
{
public:
    Results() = default;

    Results(int c, std::string& m);

    Results(int c, const char* str);

    Results(const Results& results);

    static Results success(std::string&& m);

    static Results fail(std::string&& m);

    Results& setCode(int code);

    Results& setMessage(std::string& str);

    friend void to_json(nlohmann::json& j, const Results& results);

    friend void from_json(const nlohmann::json& j, Results& results);

    Results& addData(std::string key, std::string value);

    std::string to_string();

    std::unordered_map<std::string, std::string>& getData()
    {
        return data;
    }

    NLOHMANN_DEFINE_TYPE_INTRUSIVE(Results, data);

private:
    int code{};
    std::string message{};
    std::unordered_map<std::string, std::string> data{};
};

Results doQuery(std::string& line);
#endif //COMMAND_HPP
