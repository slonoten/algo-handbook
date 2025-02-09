// Ищем индекс значения в отсортированном массиве не повторяющихся чисел

#include <iostream>
#include <ranges>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include <optional>


template<typename It, typename V> std::optional<std::tuple<It, It> > bin_range_search(It begin, It end, V query) {
    auto notFound{end};
    while(begin <= end) {
        auto middle{begin + (end - begin) / 2};
        if (*middle == query) {
            return std::make_tuple(begin, end); 
        }
        if (*middle > query) {
            end = middle - 1;
        } else {
            begin = middle + 1;
        }
    }
    return std::nullopt;
}


template<typename It, typename V> It bin_search(It begin, It end, V query, bool find_last) {
    auto it = end;
    while(begin <= end) {
        auto middle{begin + (end - begin) / 2};
        if (*middle == query) {
            it = middle;
            if (find_last) {
                begin = middle + 1;
            } else {
                end = middle - 1;
            }
            continue;
        }
        if (*middle > query) {
            end = middle - 1;
        } else {
            begin = middle + 1;
        }
    }
    return it;
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
        size_t count{0ul};
        if (auto res = bin_range_search(keys.begin(), keys.end(), q))
        {
            auto [begin, end] = res.value();
            auto first = bin_search(begin, end, q, false);
            auto last = bin_search(begin, end, q, true);
            count = last - first + 1;
        }
        std::cout << count << " ";
    }
}