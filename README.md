# filter_cpp

This project is a C++ implementation inspired by Rust's filter functionality.

## Getting Started

### Prerequisites

- A C++ compiler supporting C++14 or later.

- CMake for build configuration (optional but recommended).

### Building the Project

1. Clone the Repository:

    ```bash
    git clone https://github.com/fpena2/filter_cpp.git
    cd filter_cpp
    ```

2. Build and run tests

    ```bash
    ./build.sh
    ```

## Usage

The `filter` function allows for processing elements in a collection based on a specified predicate. Here's an example of how to use it:

```cpp
#include "filter.h"
#include <vector>
#include <iostream>

int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 5};
    auto is_even = [](int n) { return n % 2 == 0; };

    auto result = filter(numbers, is_even);

    for (int n : result) {
        std::cout << n << std::endl; // Outputs: 2 4
    }

    return 0;
}
```
