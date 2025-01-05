#include <cassert>
#include <array>
#include <iostream>

#include "merge.hpp"

template<class T> void print(T& vec) {
    for (auto v: vec) {
        std::cout << v << " ";
    }
    std::cout << "\n";
}


void check1() {
    std::vector<int> v1{2, 4, 6};
    std::vector<int> v2{1, 3, 5};
    auto result = merge<int>(v1, v2);
    std::vector<int> true_values = {1, 2, 3, 4, 5, 6};    
    assert(true_values == result);
}


void check2() {
    std::vector<int> v1{};
    std::vector<int> v2{1, 3, 5};
    auto result = merge<int>(v1, v2);
    std::vector<int> true_values = {1, 3, 5};    
    assert(true_values == result);
}

void check3() {
    std::vector<int> v1{1, 3, 5};
    std::vector<int> v2{};
    auto result = merge<int>(v1, v2);
    std::vector<int> true_values = {1, 3, 5};    
    assert(true_values == result);
}

void check4() {
    std::vector<int> v1{2, 4, 6};
    std::vector<int> v2{1, 3, 5};
    std::vector<std::vector<int> > sequences{v1, v2};
    auto result = merge_sequences(sequences);
    std::vector<int> true_values = {1, 2, 3, 4, 5, 6};    
    assert(true_values == result);
}

void check5() {
    std::vector<int> v1{2, 4, 6};
    std::vector<int> v2{1, 3, 5};
    std::vector<int> v3{0, 7, 8};
    std::vector<std::vector<int> > sequences{v1, v2, v3};
    auto result = merge_sequences(sequences);
    std::vector<int> true_values = {0, 1, 2, 3, 4, 5, 6, 7, 8};    
    print(result);
    assert(true_values == result);
}

int main() {
    std::cout << "First check...";
    check1();
    std::cout << " Ok\n";    
    std::cout << "Second check...";
    check2();
    std::cout << " Ok\n";    
    std::cout << "Third check...";
    check3();
    std::cout << " Ok\n";    
    std::cout << "Forth check...";
    check4();
    std::cout << " Ok\n";    
    std::cout << "Fifth check...";
    check5();
    std::cout << " Ok\n";    
    std::cout << "Completed\n";    
}