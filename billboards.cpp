#include <iostream>
#include <ranges>
#include <array>
#include <vector>
#include <algorithm>

int main() {
    int n, k, w;
    std::cin >> n >> k >> w;
    std::vector<std::pair<int, int>> bids(k);
    for (auto& [price, weeks] : bids) {
        std::cin >> price >> weeks;
    }
    std::ranges::sort(bids);
    long income{0};
    std::vector<int> bbCapacities(n, w);
    for (int free_weeks = w * n; free_weeks > 0 && !bids.empty();) {
        auto& [price, weeks] = bids.back();
        bids.pop_back();
        if (weeks > w ) {
            weeks = w;
        }
        if (weeks > free_weeks) {
            weeks = free_weeks;
        }
        income += price * weeks;
        free_weeks -= weeks;
    }
    std::cout << income << std::endl;
}