#pragma once

// Internal libs
#include "iterator.h"

// C++ libs
#include <vector>
#include <functional>

class filter
{
private:
    std::vector<int> v;
    std::function<bool(int)> filter_func;

public:
    filter(const std::vector<int> &v, const std::function<bool(int)> &func)
        : v(v), filter_func(func) {}

    iterator begin()
    {
        iterator iter(v.begin(), v.end(), filter_func);
        while (iter != end() && !filter_func(*iter))
        {
            ++iter;
        }
        return iter;
    }

    iterator end() { return iterator(v.end(), v.end(), filter_func); }
};