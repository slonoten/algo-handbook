/* Вы играете в игру <<Камни>>: игру для двух игроков с двумя наборами камней по 
𝑛
n и 
𝑚
m штук. С каждым ходом один игрок может забрать следующие комбинации камней:

Взять один камень из любого набора.
Взять два камня из какого-то одного набора
Взять два камня из одного и один из другого.
Когда камень забрали, он выходит из игры. Побеждает игрок, который заберет последний камень. Первый ход за вами.

Вы и ваш оппонент играете оптимально. */

/*
lwwlwu
wlwwlu
wwlwwu
lwwluu
wlww
*/


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;




bool isWin(size_t n, size_t m, vector<vector<bool> >& predicts);

int main() {
    size_t n, m;
    cin >> n >> m;
    auto predicts = vector<vector<bool> >(n + 1, vector(m + 1, true));
    for (size_t i = 0; i <= n; i++) {
        for (size_t j = 0; j <= m; j++) {
            predicts[i][j] = isWin(i, j, predicts);
        }
    }

    if (predicts[n][m]) {
        cout << "Win";
    } else {
        cout << "Loose";
    }
}


bool isWin(size_t n, size_t m, vector<vector<bool> >& predicts) {
    if (n > 0 && !predicts[n - 1][m])
        return true;
    if (m > 0 && !predicts[n][m - 1])
        return true;
    if (n > 1 && !predicts[n - 2][m])
        return true;
    if (m > 1 && !predicts[n][m - 2])
        return true;
    if (n > 1 && m > 0 && !predicts[n - 2][m - 1])
        return true;
    if (n > 0 && m > 1 && !predicts[n - 1][m - 2])
        return true;
    return false;
}