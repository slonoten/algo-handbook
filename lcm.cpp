#include <iostream>

using namespace std;


int gcd(long a, long b) {
    while (a > 0 && b > 0) {
        if (a > b) {
            a = a % b;
        } else {
            b = b % a;
        }
    }
    return max(a, b);
}


int main() {
    long a, b;
    cin >> a >> b;

    cout << a / gcd(a, b) * b << endl;
}