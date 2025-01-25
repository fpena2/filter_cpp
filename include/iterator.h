#pragma once

// C++ libs
#include <vector>
#include <functional>

class iterator
{
    std::vector<int>::iterator curr_iter;
    const std::vector<int>::iterator end;
    std::function<bool(int)> filter_func;

public:
    iterator(std::vector<int>::iterator iter, std::vector<int>::iterator end,
             const std::function<bool(int)> &condition)
        : curr_iter(iter), end(end), filter_func(condition)
    {
        // Move curr_iter to a valid first value
        while (curr_iter != end && !filter_func(*curr_iter))
        {
            curr_iter++;
        }
    }

    int operator*() const
    {
        return *curr_iter;
    }

    bool operator==(const iterator &other) const
    {
        return curr_iter == other.curr_iter;

        // TODO: check for the entire range?
        // && end == other.end
        // && filter_func.target_type() == other.filter_func.target_type();
    }

    bool operator!=(const iterator &other) const
    {
        return !(*this == other);
    }

    iterator &operator++()
    {
        do
        {
            ++curr_iter;
        } while (curr_iter != end && !filter_func(*curr_iter));

        return *this;
    }
};