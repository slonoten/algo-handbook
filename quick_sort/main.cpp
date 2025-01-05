#include <iostream>
#include <vector>
#include <span>

#include "quick_sort.hpp"

int main() {
    size_t n;
    std::cin >> n;
    std::vector<int> sequence(n);
    for (auto& v: sequence)
    {
        std::cin >> v;
    }
    std::span data{sequence};
    quick_sort(data);
    for (auto v: sequence) {
        std::cout << v << " ";
    }
}