#include <iostream>
#include <algorithm>
#include <vector>
#include <ranges>


int main() {
    size_t n;
    std::cin >> n;
    std::vector<long> numbers(n);
    for (auto& v: numbers) {
        std::cin >> v;
    }

    std::ranges::sort(numbers);

    auto max_prod {std::max(numbers[n - 1] * numbers[n - 2] * numbers[n - 3], numbers[0] * numbers[1] * numbers[n - 1])};

    std::cout << max_prod;
}