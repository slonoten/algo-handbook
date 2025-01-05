#include <iostream>
#include <vector>

#include "merge.hpp"

int main() {
    size_t n;
    std::cin >> n;
    std::vector<std::vector<int> > sequences(n);
    for (auto& seq: sequences)
    {
        size_t seq_len;
        std::cin >> seq_len;
        seq.resize(seq_len);
        for (auto& v: seq) {
            std::cin >> v;
        }
    }
    auto result{merge_sequences(sequences)};
    for (auto v: result) {
        std::cout << v << " ";
    }
}