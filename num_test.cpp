#include<iostream>

int main() {
    int a{0x7fffffff};
    std::cout << a << std::endl;
    long b{0};
    b += a;
    b += a;
    std::cout << b << std::endl;
}