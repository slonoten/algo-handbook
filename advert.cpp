#include <iostream>
#include <ranges>
#include <vector>
#include <sstream>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> prices(n), clicks(n);
    std::copy_n(std::istream_iterator<int>(std::cin), n, prices.begin());
    std::copy_n(std::istream_iterator<int>(std::cin), n, clicks.begin());

    std::ranges::sort(prices);
    std::ranges::sort(clicks);

    long money{0};

    for(auto i: std::ranges::views::iota(0, n)) {
        money += clicks[i] * prices[i];
    }
    std::cout << money << std::endl;
}
