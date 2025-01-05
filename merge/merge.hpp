#pragma once

#include <vector>


template<typename T> std::vector<T> merge(const std::vector<T>& left, const std::vector<T>& right) {
    std::vector<T> result(left.size() + right.size());
    size_t left_pos{0}, right_pos{0};
    for(auto& v: result) {
        if (left_pos >= left.size())
        {
            v = right[right_pos++];
        }
        else if (right_pos >= right.size())
        {
            v = left[left_pos++];
        }
        else if (left[left_pos] < right[right_pos]){
            v = left[left_pos++];
        }
        else {
            v = right[right_pos++];
        }
    }
    return result;
}

template<typename T> std::vector<T> merge_sequences(const std::vector<std::vector<T> >& sequences) {
    if (sequences.size() == 0)
        return std::vector<T>();  // return empty
    if (sequences.size() == 1)
        return std::vector<T>(sequences.front()); // return copy
    size_t idx = 0;
    std::vector<T> result = merge(sequences[idx++], sequences[idx++]);
    while (idx < sequences.size())
    {
        result = merge(result, sequences[idx++]);
    }
    return result;
}