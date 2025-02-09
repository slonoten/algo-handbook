/*В теннисном турнире принимают участие n роботов-спортсменов. Про каждого из них известно, насколько хорошо он играет. 
Умение i-го робота описывается числом a_i. В игре двух роботов всегда побеждает тот, у кого умение играть в теннис больше.
В этой задаче мы будем полагать, что все значения a_i различны.
В каждом раунде теннисного турнира роботы разбиваются на пары. Если количество продолжающих участие в турнире нечетное,
то один из роботов без игры проходит в следующий раунд. После игры в каждой из пар, в следующий раунд выходит победитель,
а проигравший выбывает из турнира.

Определите, какое наибольше количество игр в турнире может выиграть k-й робот-спортсмен.*/


#include <iomanip>
#include <iostream>
#include <ranges>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>



bool isOdd(auto x) {
    return x % 2;
}


int main() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> strength(n);
    std::copy_n(std::istream_iterator<int>(std::cin), n,  strength.begin());
    auto kStrength = strength[k - 1];
    std::ranges::sort(strength);
    auto i = std::ranges::lower_bound(strength, kStrength) - strength.begin();
    auto weakCount =  i;
    auto strongCount = n - i - 1;
    size_t winCount{0};
    while(weakCount) {
        winCount++;
        weakCount -= 1; // Нашему роботу победа, а слабый выбывает
        
        if (isOdd(weakCount)) {
            if (isOdd(strongCount)) {
                // Total is even
                strongCount = (strongCount - 1) / 2 + 1; // Extra strongone beats weakone
                weakCount = (weakCount - 1) / 2;
            } else {
                // Total is odd
                strongCount /= 2;
                weakCount = (weakCount - 1) / 2 + 1; // Один слабый проходит в следующий тур без игры
            } 
        } else {
            if (isOdd(strongCount)) {
                // Total is odd
                weakCount /= 2;
                strongCount = (strongCount - 1) / 2 + 1;
            } else {
                // Total is even
                weakCount /= 2;
                strongCount /= 2;
            }
        }
    }
    // std::ranges::copy(numbers, std::ostream_iterator<std::string>(std::cout, ","));
    std::cout << winCount << std::endl;
}