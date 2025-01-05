#include <iostream>
#include <vector>
#include <ranges>

namespace rng = std::ranges;
namespace view = rng::views;


int main() {
    size_t n, m;
    std::cin >> n >> m;
    std::vector<long> fibNums{0, 1};
    fibNums.resize(m * m + 1);
    size_t period;
    for (auto i : view::iota(2ul, fibNums.size() + 1)) {
        fibNums[i] = (fibNums[i - 2] + fibNums[i - 1]) % m;
        if (fibNums[i - 1] == 0 && fibNums[i] == 1) {
            period = i - 1;
            break;
        }
    }
    std::cout << fibNums[n % period];
}
