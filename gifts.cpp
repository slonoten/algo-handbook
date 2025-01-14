#include <iomanip>
#include <iostream>
#include <limits>
#include <ranges>
#include <tuple>
#include <vector>
#include <sstream>
#include <algorithm>


int main() {
    std::istream_iterator<int> input(std::cin);
    int n {*input++}, money {*input++};
    std::vector<int> prices(n);
    std::copy_n(input, n, prices.begin());

    std::ranges::sort(prices);
    int giftsNum{0};
    std::ranges::find_if(prices, [&giftsNum, &money](auto price) {
        money -= price;
        if (money < 0) {
            return true;
        } else {
            giftsNum++;
            return false;
        }
    });
    std::cout << giftsNum;
}