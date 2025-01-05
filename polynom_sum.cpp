#include <iostream>
#include <vector>
#include <algorithm>


std::vector<int> readPolynom() {
    size_t n;
    std::cin >> n;
    std::vector<int> coefs(n + 1);
    for (auto& v: coefs) {
        std::cin >> v;
    }
    return coefs;
}


std::vector<int> sumPolynom(std::vector<int>& coefsLeft, std::vector<int>& coefsRight) {
    if (coefsLeft.size() < coefsRight.size()) {
        std::swap(coefsLeft, coefsRight);
    }

    std::vector<int> coefsSum(coefsLeft.size());

    size_t rightOffset{coefsLeft.size() - coefsRight.size()};

    std::copy(coefsLeft.begin(), coefsLeft.begin() + rightOffset, coefsSum.begin());

    for (size_t i{rightOffset}; i < coefsSum.size(); i++) {
        coefsSum[i] = coefsLeft[i] + coefsRight[i - rightOffset];
    }

    return coefsSum;
}


int main() {
    auto coefsLeft = readPolynom();
    auto coefsRight = readPolynom();
    auto coefsSum = sumPolynom(coefsLeft, coefsRight);
    std::cout << coefsSum.size() - 1 << "\n";
    for (auto& v: coefsSum) {
        std::cout << v << " ";
    }
}