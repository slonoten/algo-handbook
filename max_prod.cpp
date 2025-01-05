#include <iostream>
#include <algorithm>

int main() {
    size_t n;
    std::cin >> n;
    long max1{0}, max2{0};
    std::cin >> max1;
    for (int i{1}; i < n; i++) {
        long  val;
        std::cin >> val;
        if (val > max2) {
            if (val > max1) {
                std::swap(max1, max2);
                max1 = val;
            }
            else {
                max2 = val;
            }
        }
    }
    std::cout << max1 * max2;
}