//
// Created by admin on 25-5-21.
//

#include "dict.hpp"

Node::Node(const std::string& k, const std::string& v, size_t t)
{
    key = k;
    value = v;
    this->t = t;
}
