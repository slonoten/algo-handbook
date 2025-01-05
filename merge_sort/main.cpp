#include <iostream>
#include <vector>
#include <span>

#include "merge_sort.hpp"

int main() {
    size_t n;
    std::cin >> n;
    std::vector<int> sequence(n);
    for (auto& v: sequence)
    {
        std::cin >> v;
    }
    std::span data{sequence};
    auto result{merge_sort(data)};
    for (auto v: result) {
        std::cout << v << " ";
    }
}