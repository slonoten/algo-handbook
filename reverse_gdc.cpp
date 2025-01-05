#include <iostream>
#include <tuple>

using namespace std;


int countGdcSteps(long a, long b) {
    long step_count{0};
    while (a > 0 && b > 0) {
        if (a > b) {
            a = a % b;
        } else {
            b = b % a;
        }
        step_count++;
    }
    return step_count;
}


tuple<long, long> reverseGcd(long n) {
    long a{0}, b{1};
    while (a + b <= n) {
        if (a > b) {
            b = a + b;
        } else {
            a = b + a;
        }
    }
    return make_tuple(min(a, b), max(a, b));
}


int main() {
    long n;
    cin >> n;
    long a, b;
    tie(a, b) = reverseGcd(n);

    cout << a << " " << b << endl;

    // cout << countGdcSteps(a, b) << endl;
}