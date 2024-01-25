// Internal libs
#include "filter.h"

// C++ libs
#include <iostream>

// Custom Functions
auto isOdd = [](int num)
{ return num % 2 != 0; };
auto isEven = [](int num)
{ return num % 2 == 0; };

int main()
{
    std::vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    filter even_vec(vec, isEven);
    filter odd_vec(vec, isOdd);

    std::cout << "Even numbers:" << std::endl;
    for (auto i : even_vec)
    {
        std::cout << i << std::endl;
    }

    std::cout << "Odd numbers:" << std::endl;
    for (auto i : odd_vec)
    {
        std::cout << i << std::endl;
    }

    return 0;
}
