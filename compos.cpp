#include <iostream>

long fact(int n) {

    long fact = 1;
    for(; n > 1; n--) {
        fact *= n;
    }
    return fact;
}

long compos(int n, int k) {
    return fact(n) / fact(n - k) / fact(k);
}

int main()
{
    int n, k;
    std::cin >> n >> k;
    long c = compos(n + k - 1, k);
    std::cout << c;
}
