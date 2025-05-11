//
// Created by admin on 25-5-11.
//

#include "Command.hpp"

#include <functional>
#include <future>
#include <iostream>
#include <utility>

#include "json.hpp"

std::unordered_map<std::string, std::function<Results()>> CmdMap;

Results::Results(int c, std::string& m): code(c), message(m)
{
    data = std::unordered_map<std::string, std::string>();
}

Results::Results(int c, const char* str): code(c)
{
    message = std::string(str);
    data = std::unordered_map<std::string, std::string>();
}

Results::Results(const Results& results)
{
    code = results.code;
    message = std::string(results.message);
    data = results.data;
}

Results Results::success(std::string&& m)
{
    return Results(200, m);
}

Results Results::fail(std::string&& m)
{
    return Results(400, m);
}

Results& Results::setCode(int code)
{
    this->code = code;
    return *this;
}

Results& Results::setMessage(std::string& str)
{
    this->message = str;
    return *this;
}

Results& Results::addData(std::string key, std::string value)
{
    data[key] = std::move(value);
    return *this;
}

std::string Results::to_string()
{
    nlohmann::json j = *this;
    return j.dump(4);
}


void to_json(nlohmann::json& j, const Results& results)
{
    j = nlohmann::json{
        {"code", results.code},
        {"message", results.message},
        {"data", results.data},
    };
}

void from_json(const nlohmann::json& j, Results& results)
{
    j.at("code").get_to(results.code);
    j.at("message").get_to(results.message);
    j.at("data").get_to(results.data);
}

typedef std::function<Results()> Func;

template <typename F, typename... Args>
auto Bind(F&& f, Args&&... args) -> std::future<typename std::result_of<F(Args...)>::type>
{
    auto func = std::make_shared<std::packaged_task<Results()>>(
        std::bind(std::forward<F>(f), std::forward<Args>(args)...));
    std::function<void()> t = [func]()
    {
        (*func)();
    };
    t();
    return func->get_future();
}

Results Get(std::string& key)
{
    std::cout << "Get:" << key << std::endl;
    auto res = Results::success("query okok!");
    res.addData(key, "123");
    return res;
}

Results doQuery(std::string& line)
{
    std::cout << "doquery:" << line << std::endl;
    auto d = [line]()-> std::string
    {
        switch (line[0])
        {
        case '1':
            return "111\n";
        case '2':
            return "222\n";
        default:
            return "333\n";
        }
    };
    auto cmd = d();
    auto f = Bind(Get, cmd);
    auto r = f.get();
    return r;
}
