#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

enum Predict { win, loose, unknown };

bool isWin(size_t n, size_t m, vector<vector<Predict> > cache);

int main() {
    size_t n, m;
    cin >> n >> m;
    auto cache = vector<vector<Predict> >(n + 1, vector(m + 1, unknown));
    cache[0][0] = loose;

    if (isWin(n, m, cache)) {
        cout << "Win";
    } else {
        cout << "Loose";
    }
}


bool isWin(size_t n, size_t m, vector<vector<Predict> > cache) {
    Predict& pred = cache[n][m];
    if (pred != unknown) {
        return pred == win;
    }
    bool res;
    if (n == 0) {
        res = !isWin(n, m - 1, cache);
    } else if (m == 0)
    {
        res = !isWin(n - 1, m, cache);
    } else {
        res = !(isWin(n - 1, m - 1, cache) && isWin(n - 1, m, cache) && isWin(n, m - 1, cache));
    }
    pred = res ? win : loose;
    return res;
}