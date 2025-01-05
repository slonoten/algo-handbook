#include <iostream>
#include <list>
#include <tuple>

using namespace std;


int Move(int n, int from, int to, list<tuple<int, int>>& moves) {
    if (n > 1) {
        int temp {6 - from - to};
        int moveCount {Move(n - 1, from, temp, moves)};
        moves.push_back(tuple(from, to));
        moveCount += 1 + Move(n - 1, temp, to, moves);
        return moveCount;
    }
    moves.push_back(tuple(from, to));
    return 1;
}


int main() {
    int n;
    cin >> n;
    list<tuple<int, int> > moves;
    cout << Move(n, 1, 3, moves) << "\n";
    for (auto move: moves) {
        cout << get<0>(move) << " " << get<1>(move) << "\n";
    }
}