#pragma once

// Internal libs
#include "iterator.h"

// C++ libs
#include <vector>
#include <functional>

class filter
{
private:
    std::vector<int> vec;
    std::function<bool(int)> filter_func;

public:
    filter(const std::vector<int> &v, const std::function<bool(int)> &func)
        : vec(v), filter_func(func) {}

    iterator begin()
    {
        iterator iter(vec.begin(), vec.end(), filter_func);
        while (iter != end() && !filter_func(*iter))
        {
            ++iter;
        }
        return iter;
    }

    iterator end() { return iterator(vec.end(), vec.end(), filter_func); }
};