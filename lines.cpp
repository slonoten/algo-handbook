// Сбор подписей

#include <iostream>
#include <ranges>
#include <array>
#include <vector>
#include <algorithm>

int main() {
    size_t n, l;
    std::cin >> n >> l;
    std::vector<int> points(n);
    std::copy_n(std::istream_iterator<int>(std::cin), n, points.begin());
    std::ranges::sort(points);
    int start{points.front()};
    size_t linesCount{1};
    while (true)
    {
        auto nextNotCoveredPointIt = std::ranges::upper_bound(points, start + l);
        if (nextNotCoveredPointIt == points.end()) {
            break;
        }
        linesCount++;
        start = *nextNotCoveredPointIt;
    }
    std::cout << linesCount << std::endl;
}