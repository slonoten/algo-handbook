#include <iostream>
#include <vector>
#include <algorithm>

template<class T> void sort(T& data) {
    for (auto i{0}; i < data.size() - 1; i++) {
        int min_idx = i;
        for (auto j{i + 1}; j < data.size(); j++) {
            if (data[j] < data[min_idx]) {
                min_idx = j;
            }
        }
        std::swap(data[i], data[min_idx]);
    }
}

int main() {
    size_t n;
    std::cin >> n;
    std::vector<int> data(n);
    for (auto& v: data)
    {
        std::cin >> v;
    }
    sort(data);
    for (auto v: data) {
        std::cout << v << " ";
    }
}