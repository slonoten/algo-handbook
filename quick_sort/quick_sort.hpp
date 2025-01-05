#pragma once

#include "lomuto_partition.hpp"


template<typename T> void print(const std::span<T> vec) {
    for (auto v: vec) {
        std::cout << v << " ";
    }
    std::cout << "\n";
}


template<typename T> void quick_sort(std::span<T> data) {
    if (data.size() <= 1) {
        return;
    }
    auto idx = partition(data);
    std::cout << idx << "\n";
    print(data);
    if (idx == 0) {
        idx = 1;
    }
    quick_sort(data.subspan(0, idx));
    quick_sort(data.subspan(idx));
}