// Ищем индекс значения в отсортированном массиве не повторяющихся чисел

#include <iostream>
#include <ranges>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>


template<typename It, typename V> It bin_search(It begin, It end, V query) {
    auto notFound{end};
    while(begin <= end) {
        auto middle{begin + (end - begin) / 2};
        if (*middle == query) {
            return middle; 
        }
        if (*middle > query) {
            end = middle - 1;
        } else {
            begin = middle + 1;
        }
    }
    return notFound;
}


int main() {
    int n, q;
    std::cin >> n;
    std::vector<int> sorted(n);
    std::copy_n(std::istream_iterator<int>(std::cin), n,  sorted.begin());
    std::cin >> q;
    auto res = bin_search(sorted.begin(), sorted.end(), q);

    std::cout << (res == sorted.end()? -1: res - sorted.begin()) << std::endl;

}