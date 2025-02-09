#include <iostream>
#include <math.h>

int main() {
    int n;
    std::cin >> n;
    int maxPrizes = (sqrt(1 + 8 * n) - 1) / 2;
    std::cout << maxPrizes << std::endl;
}
