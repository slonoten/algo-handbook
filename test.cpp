#include <iostream>
#include <ranges>
#include <array>
#include <vector>
#include <algorithm>



bool isOdd(int x) {
    return x % 2;
}


int main() {
    std::vector a{0, 1, 2};
    std::ranges::sort(a);
    auto ubIt = std::ranges::lower_bound(a, 1);
    if (ubIt == a.end()) {
        std::cout << "end" << std::endl;
    }
    else {
       std::cout << ubIt - a.begin(); 
    }
    // std::vector<int> vec(2);
    // std::copy_n(std::istream_iterator<int>(std::cin), 2, vec.begin());
    // for (auto v: vec) {
    //    std::cout << v << " ";
    //}
    if (isOdd(2)) {
        std::cout << "Hi";
    }
}