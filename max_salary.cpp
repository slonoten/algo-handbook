// В качестве последнего вопроса на собеседовании будущий начальник дает вам 
// n бумажек с одним числом на каждой и говорит составить из них самое большое число. 
// Получившееся число — ваша зарплата, поэтому вы очень замотивированы решить эту задачу!

#include <iomanip>
#include <iostream>
#include <ranges>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>


int main() {
    int n;
    std::cin >> n;
    std::vector<std::string> numbers(n);
    std::copy_n(std::istream_iterator<std::string>(std::cin), n,  numbers.begin());
    std::ranges::sort(numbers, [](auto left, auto right) {
        return std::stoi(left + right) > std::stoi(right + left);
    });
    // std::ranges::copy(numbers, std::ostream_iterator<std::string>(std::cout, ","));
    std::cout << std::reduce(numbers.begin(), numbers.end());
}