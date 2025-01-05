#include <iostream>

int main() {
    size_t n;
    std::cin >> n;
    switch (n)
    {
        case 0:
            std::cout << 0;
            break;
        case 1:
            std::cout << 1;
            break;
        default:
            long fnm2{0};
            long fnm1{1};
            for (size_t i{2}; i <= n; i++)
            {
                auto fn = (fnm1 + fnm2) % 10;
                fnm2 = fnm1;
                fnm1 = fn;
            }
            std::cout << fnm1;
    }
}