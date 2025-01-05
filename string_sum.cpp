#include <iostream>


int main() {
    std::string a, b;
    size_t n;
    std::cin >> n >> a;
    for (size_t i{0}; i < n; i++) {
        char ch;
        std::cin >> ch;
        std::cout << a[i] << ch;
    }
    std::cout << "\n";
}