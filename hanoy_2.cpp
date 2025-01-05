#include <iostream>
#include <list>
#include <tuple>

using namespace std;


int CountMoves3Rod(int n) {
    switch (n) {
        case 0:
            return 0;
        case 1:
            return 1;
        default:
            return CountMoves3Rod(n - 1) * 2 + 1;
    } 
}

int CountMoves4Rod(int n) {
    switch (n) {
        case 0:
            return 0;
        case 1:
            return 1;
        case 2:
            return 3;
        case 3:
            return 5;
        default:
            int minMoveCount = CountMoves4Rod(n - 2) * 2 + 3;
            for (int l = 0; l < n; l++)
            {
                int m = n - l;
                int movesCount = CountMoves4Rod(l) * 2 + CountMoves3Rod(m);
                if (movesCount < minMoveCount) {
                    minMoveCount = movesCount;
                }
            } 
            return minMoveCount;
    }
}


int main() {
    int n;
    cin >> n;
    cout << CountMoves4Rod(n) << "\n";
}