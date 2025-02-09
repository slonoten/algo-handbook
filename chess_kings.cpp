#include <iostream>
#include <ranges>
#include <algorithm>
#include <vector>
#include <sstream>
#include <numeric>
#include <cassert>
#include <functional>


class Board {
    std::vector<std::vector<int>> _moveCounts;
public:
    Board(size_t rowsCount, size_t columnsCount): _moveCounts(rowsCount) {
        std::ranges::for_each(_moveCounts, [columnsCount](auto& row){row.resize(columnsCount);});
    }

    template<class T> bool visitMoves(int row, int col, T& visitor) {
        for (int i{std::max(0, row - 1)}; i < std::min(row + 2, (int)_moveCounts.size()); ++i) {
            for (int j{std::max(0, col - 1)}; j < std::min(col + 2, (int)_moveCounts[row].size()); ++j) {
                if (!(i == row && j == col)) {
                    if (!visitor(_moveCounts[i][j]))
                    {
                        return false;
                    }
                }
            }
        }
        return true;
    };

    void show() {
        for (auto& row: _moveCounts) {
            std::cout << "[";
            std::ranges::copy(row, std::ostream_iterator<int>(std::cout, " "));
            std::cout << "]" << std::endl;        
        }        
    }

    int& at(size_t row, size_t col) {
        return _moveCounts[row][col];
    }
};


struct CheckVisitor {
    bool hasMove = false;

    bool operator()(int& moveCount) {
        switch(moveCount) {
        case 1:
            return false;
        case 0:
            hasMove = true;
        }
        return true;
    }
};

struct SetVisitor {
    size_t posibleMovesCount = 0;

    bool operator()(int& moveCount) {
        if (moveCount == 0) {
            posibleMovesCount++;
        }
        else {
            moveCount--;
        }
        return true;
    }
};


int main() {
    size_t r, c;
    std::cin >> r >> c;
    Board board(r, c);

    for (auto i: std::ranges::views::iota(0ul, r)) {
        for (auto j: std::ranges::views::iota(0ul, c)) {
            CheckVisitor checker;
            if (board.visitMoves(i, j, checker) && checker.hasMove)
            {
                SetVisitor setter;
                board.visitMoves(i, j, setter);
                assert(setter.posibleMovesCount > 0);
                board.at(i, j) = setter.posibleMovesCount;
            }
        }
    }

    // board.show();

    size_t kingsCount{0};
    for (auto i: std::ranges::views::iota(0ul, r)) {
        for (auto j: std::ranges::views::iota(0ul, c)) {
            if (board.at(i, j)) {
                kingsCount++;
            }
        }
    }

    std::cout << kingsCount << std::endl;
}
