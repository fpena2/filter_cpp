#include <gtest/gtest.h>
#include <vector>
#include <functional>
#include "filter.h"

// Custom functions
static auto isOdd = [](int num)
{ return num % 2 != 0; };
static auto isEven = [](int num)
{ return num % 2 == 0; };

TEST(FilterTest, BeginSkipsUnmatchedElements)
{
    std::vector<int> vec = {1, 3, 5, 6, 7};
    filter f(vec, isEven);
    auto it = f.begin();

    EXPECT_EQ(*it, 6);
}

TEST(FilterTest, EndPointsToEnd)
{
    std::vector<int> vec = {1, 3, 5, 6, 7};
    filter f(vec, isEven);
    auto it = f.begin();
    auto end = f.end();

    std::vector<int> result;
    while (it != end)
    {
        result.push_back(*it);
        ++it;
    }

    EXPECT_EQ(result, std::vector<int>({6}));
}

TEST(FilterTest, WorksForOddNumbers)
{
    std::vector<int> vec = {1, 2, 3, 4, 5, 6};
    filter f(vec, isOdd);

    std::vector<int> result;
    for (auto num : f)
    {
        result.push_back(num);
    }

    EXPECT_EQ(result, std::vector<int>({1, 3, 5}));
}

TEST(FilterTest, HandlesEmptyVector)
{
    std::vector<int> empty_vec;
    filter f(empty_vec, isEven);

    auto it = f.begin();
    auto end = f.end();

    EXPECT_EQ(it, end);
}
