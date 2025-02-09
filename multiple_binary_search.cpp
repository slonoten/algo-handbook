// Ищем индекс значения в отсортированном массиве не повторяющихся чисел

#include <iostream>
#include <ranges>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>


int search(auto arr, auto query) {
    int min_idx {0},  max_idx{static_cast<int>(arr.size() - 1)};
    while(min_idx <= max_idx) {
        auto mid_idx{(min_idx + max_idx) >> 1};
        auto key{arr[mid_idx]};
        if (key == query) {
            return mid_idx; 
        }
        if (key > query) {
            max_idx = mid_idx - 1;
        } else {
            min_idx = mid_idx + 1;
        }
    }
    return -1;
}


int main() {
    int n, m;
    std::cin >> n;
    std::vector<int> keys(n);
    std::copy_n(std::istream_iterator<int>(std::cin), n,  keys.begin());
    std::cin >> m;
    std::vector<int> queries(m);
    std::copy_n(std::istream_iterator<int>(std::cin), m,  queries.begin());
    for (auto q: queries) {
        std::cout << search(keys, q) << std::endl;
    }
}