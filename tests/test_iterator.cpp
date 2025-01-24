#include <gtest/gtest.h>
#include <vector>
#include <functional>
#include "iterator.h"

// Custom functions
static auto isOdd = [](int num)
{ return num % 2 != 0; };
static auto isEven = [](int num)
{ return num % 2 == 0; };

TEST(IteratorTest, IteratesCorrectlyWithCondition)
{
    std::vector<int> vec = {1, 2, 3, 4, 5};
    iterator it(vec.begin(), vec.end(), isEven);
    iterator end(vec.end(), vec.end(), isEven);

    std::vector<int> result;
    while (it != end)
    {
        result.push_back(*it);
        ++it;
    }

    EXPECT_EQ(result, std::vector<int>({2, 4}));
}

TEST(IteratorTest, HandlesEmptyVector)
{
    std::vector<int> empty_vec;
    iterator it(empty_vec.begin(), empty_vec.end(), isEven);
    iterator end(empty_vec.end(), empty_vec.end(), isEven);

    EXPECT_EQ(it, end);
}
