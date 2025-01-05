#include <iostream>
#include <ranges>
#include <array>
#include <vector>
#include <sstream>
#include <numeric>

int main() {
    std::array<int, 5> coinNominals = {50, 20, 10, 5, 1};
    std::vector<int> nomCounts(5);
    int money;
    std::cin >> money;
    for (const auto& [nom, nomCount] : std::views::zip(coinNominals, nomCounts)) {
        nomCount = money / nom;
        money %= nom;
    }
    std::cout << std::reduce(nomCounts.begin(), nomCounts.end()) << std::endl; 
    for (auto i{0}; i < coinNominals.size(); i++)
    {
        for (auto j{0}; j < nomCounts[i]; j++)
        {
            std::cout << coinNominals[i] << " ";
        }
    }
}