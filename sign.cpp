// Сбор подписей

#include <iostream>
#include <ranges>
#include <array>
#include <vector>
#include <algorithm>

int main() {
    size_t n;
    std::cin >> n;
    std::vector<std::pair<int, int>> ranges(n);
    std::ranges::for_each(ranges, [](auto& range) { std::cin >> range.first >> range.second; });
    std::ranges::sort(ranges, {}, &std::pair<int, int>::first);
    std::vector<int> points;
    while(!ranges.empty()) {
        auto [x, point] = std::ranges::min(ranges, {}, &std::pair<int, int>::second);
        points.push_back(point);
        auto firstNotSignedIt = std::ranges::upper_bound(ranges, point, {}, &std::pair<int, int>::first);
        ranges.erase(ranges.begin(), firstNotSignedIt);
    }
    std::cout << points.size() << std::endl;
    std::cout << points.front();
    std::for_each(++points.begin(), points.end(), [](auto point){ std::cout << " " << point; });
    std::cout << std::endl;
}
