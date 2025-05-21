//
// Created by admin on 25-5-21.
//

#ifndef DICT_HPP
#define DICT_HPP
#include <string>
#include <vector>

class Node
{
public:
    Node(const std::string& k, const std::string& v, size_t t = 0);

private:
    std::string key;
    std::string value;
    size_t t{0};
};

#endif //DICT_HPP
