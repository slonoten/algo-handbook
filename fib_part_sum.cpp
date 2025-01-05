#include <iostream>
#include <vector>
#include <ranges>

namespace rng = std::ranges;
namespace view = rng::views;


long fibSum(size_t n) {
    const size_t m{10};
    std::vector<long> fibNums{0, 1};
    fibNums.resize(m * m + 1);
    std::vector<long> fibSums{0, 1};
    fibSums.resize(m * m + 1);    
    size_t period;
    for (auto i : view::iota(2ul, fibNums.size() + 1)) {
        fibNums[i] = (fibNums[i - 2] + fibNums[i - 1]) % m;
        if (fibNums[i - 1] == 0 && fibNums[i] == 1) {
            period = i - 1;
            break;
        }
        fibSums[i] = (fibSums[i - 1] + fibNums[i]) % m;
    }
    long inc{fibSums[period - 1]};
    std::vector<long> sumStarts(m);
    for (size_t i{0}; i < m; i++) {
        sumStarts[i] = (i * inc) % m;
    }
    
    return (fibSums[n % period] + sumStarts[n % period % m]) % m;
}


int main() {
    size_t n, m;
    std::cin >> n >> m;

    long leftSum{n ? fibSum(n - 1) : 0};
    long rightSum(fibSum(m));

    std::cout << (10 + rightSum - leftSum) % 10;
}