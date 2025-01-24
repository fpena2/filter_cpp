#include "filter.h"
#include <gtest/gtest.h>
#include <vector>
#include <algorithm>

TEST(FilterTest, FiltersEvenNumbers)
{
    std::vector<int> numbers = {1, 2, 3, 4, 5};
    auto is_even = [](int n)
    { return n % 2 == 0; };

    auto result = filter(numbers, is_even);

    std::vector<int> expected = {2, 4};
    auto expected_it = expected.begin();
    for (auto value : result)
    {
        EXPECT_EQ(value, *expected_it);
        ++expected_it;
    }
}
