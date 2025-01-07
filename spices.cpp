#include <iomanip>
#include <iostream>
#include <limits>
#include <ranges>
#include <tuple>
#include <vector>
#include <sstream>
#include <algorithm>


int main() {
    int n, volume;
    std::cin >> n >> volume;
    std::vector<std::tuple<int, int> > spices(n);
    for (auto& [price, amount]: spices) {
        std::cin >> price >> amount;
    }

    std::ranges::sort(spices, [](auto const &t1, auto const &t2) {
        return double(get<0>(t1)) / get<1>(t1) > double(get<0>(t2)) / get<1>(t2);
    });

    long value {0};
    long rest {0};
    for (auto[price, amount]: spices) {
        if (amount <= volume) {
            value += price;
            volume -= amount;
        } else {
            rest = price * 10000 * volume / amount;
            break;
        }
    }
    if (rest % 10000) {
        std::cout << value + rest / 10000 << "." << std::setfill('0') << std::setw(4) << rest % 10000;
    }
    else {
        std::cout << value + rest / 10000;        
    }
}