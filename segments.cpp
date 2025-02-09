// Выведите минимальную длину k отрезков, покрывающих все точки. Отметим, что отрезки могут иметь нулевую длину.

#include <iostream>
#include <ranges>
#include <array>
#include <vector>
#include <numeric>
#include <algorithm>

int main() {
    size_t n, k;
    std::cin >> n >> k;
    std::vector<int> points(n);
    std::copy_n(std::istream_iterator<int>(std::cin), n, points.begin());
    if (k >= n) {
        std::cout << 0 << std::endl;
        return 0;
    }    
    std::ranges::sort(points);
    std::vector<unsigned int> distances(n - 1);
    for (auto i: std::ranges::views::iota(0ul, n - 1)) {
        distances[i] = points[i + 1] - points[i];
    }
    std::ranges::sort(distances, std::greater{});
    auto offset = k - 1;
    std::cout <<  points.back() - points.front() - std::reduce(distances.begin(), distances.begin() + offset) << std::endl;
}