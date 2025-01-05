#pragma once

#include <span>
#include <stdexcept>

template<typename T> size_t partition(std::span<T>& data) {
    if (data.size() == 0) {
        throw std::invalid_argument("Empty span is invalid");
    }
    if (data.size() == 1)
    {
        return 0;
    }
    if (data.size() == 2)
    {
        if (data[0] < data[1])
        {
            return 0;
        } 
        std::swap(data[0], data[1]);
        return 1;
    }
    auto first_major_idx{0};
    for (auto i{1}; i < data.size(); i++) {
        if (data[i] > data[0]) {
            first_major_idx = i;
            break;
        }
    }
    if (first_major_idx == 0)
    {
        std::swap(data[0], data[data.size() - 1]);
        return data.size() - 1;
    }
    for (auto i{first_major_idx + 1}; i < data.size(); i++)
    {
        if (data[i] <= data[0])
        {
            std::swap(data[i], data[first_major_idx++]);
        }
    }
    std::swap(data[0], data[first_major_idx - 1]);
    return first_major_idx - 1;
}
