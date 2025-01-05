#include <iostream>

int main() {
    int n;
    std::cin >> n;
    long fact = 1;
    for(; n > 1; n--) {
        fact *= n;
    }
    std::cout << fact;
}
