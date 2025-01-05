#include <random>
#include <iostream>
#include <cmath>
#include <vector>


int main()
{
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist(0,1000); // distribution in range [1, 6]
    size_t n{100000};
    std::vector<int> numbers(n);
    for (auto& v: numbers)
    {
        v = dist(rng);
    }
    size_t compNumber{0};
    
    int max1{numbers[0]}, max2{numbers[1]};
    if (max1 < max2) {
        std::swap(max1, max2);
        compNumber++;
    }

    for (int i{2}; i < n; i++) {
        compNumber++;
        if (numbers[i] > max2) {
            compNumber++;
            if (numbers[i] > max1) {std::swap(max1, max2);
                max2 = max1;
                max1 = numbers[i];
            }
            else
            {
                max2 = numbers[i];
            }
        }
        else {

        }
    }
    std::cout << "N: " << n << "\n";
    std::cout << "Число сравнений: " << compNumber << "\n";
    std::cout << "1.5 N:" << n * 1.5 << "\n";
    std::cout << "N + log2(N) - 2: " << n + std::ceil(std::log2(n)) - 2 << "\n";    
}