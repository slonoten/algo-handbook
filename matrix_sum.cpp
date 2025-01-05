#include <vector>
#include <iostream>


int main() {
    size_t n, m;
    std::cin >> n >> m;
    int a[n][m];
    for (auto i = 0; i < n; i++) {
        for (auto j = 0; j < m; j++) {
            std::cin >> a[i][j];
        }
    }

    for (auto i = 0; i < n; i++) {
        for (auto j = 0; j < m; j++) {
            int x;
            std::cin >> x;
            std::cout << x + a[i][j] << " ";
        }
        std::cout << "\n";
    } 
}