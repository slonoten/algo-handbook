#include <vector>
#include <span>


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


template<typename T> std::vector<T> merge_sort(const std::span<T> data) {
    if (data.size() <= 1)
    {
        return std::vector<T>(data.begin(), data.end());
    }
    size_t half = data.size() / 2;
    auto left = merge_sort(data.subspan(0, half));
    auto right = merge_sort(data.subspan(half));
    return merge(left, right);
}