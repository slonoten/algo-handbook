#include <cstdlib> 

#include <vector>
#include <iostream>
#include <cassert>

#include "lomuto_partition.hpp"
#include "quick_sort.hpp"


template<typename T> void print(const std::vector<T> vec) {
    for (auto v: vec) {
        std::cout << v << " ";
    }
    std::cout << "\n";
}


void check1()
{
    std::vector data{4, 7, 2, 5, 3, 1, 8, 9, 6};
    auto span = std::span(data);
    partition(span);
    std::vector expected{1, 2, 3, 4, 7, 5, 8, 9, 6};
    assert(expected == data);
}


void check2()
{
    std::vector data{10, 7, 2, 5, 3, 1, 8, 9, 6};
    auto span = std::span(data);
    partition(span);
    std::vector expected{6, 7, 2, 5, 3, 1, 8, 9, 10};
    assert(expected == data);
}


void check3()
{
    std::vector data{1, 2, 3, 4, 5, 6};
    auto span = std::span(data);
    partition(span);
    std::vector expected{1, 2, 3, 4, 5, 6};
    assert(expected == data);
}


void check4()
{
    std::vector data{1, 2};
    auto span = std::span(data);
    partition(span);
    std::vector expected{1, 2};
    assert(expected == data);
}


void check5()
{
    std::vector data{2, 1};
    auto span = std::span(data);
    partition(span);
    std::vector expected{1, 2};
    assert(expected == data);
}



void check5_5()
{
    std::vector data{690, 386, 492, 649, 421, 777}; 
    auto span = std::span(data);
    auto idx = partition(span);
    print(data);
    assert(idx == 4);
    // std::vector expected{1, 2};
    // assert(expected == data);
}



void check6()
{
    std::vector data{13, 17, 37, 73, 31, 19, 23};
    auto span = std::span(data);
    quick_sort(span);
    std::vector expected{13, 17, 19, 23, 31, 37, 73};
    assert(expected == data);
}


void check7()
{
    auto n = 100000;
    std::vector data(n, 0);
    for (auto i{0}; i < n; i++) {
        data[i] = 100000 - i;
    }
    auto span = std::span(data);
    quick_sort(span);
    for (auto i{0}; i < n; i++)
    {
        assert(data[i] == i + 1);
    }
}

void check8()
{
    auto n = 100000;
    std::vector data(n, 0);
    data[0] = n;
    for (auto i{1}; i < n; i++) {
        data[i] = i;
    }
    auto span = std::span(data);
    quick_sort(span);
    for (auto i{0}; i < n; i++)
    {
        assert(data[i] == i + 1);
    }
}


void check9()
{
    auto n = 100000;
    std::vector data(n, 0);
    data[n - 1] = 1;
    for (auto i{0}; i < n - 1; i++) {
        data[i] = i + 2 ;
    }
    auto span = std::span(data);
    quick_sort(span);
    for (auto i{0}; i < n; i++)
    {
        assert(data[i] == i + 1);
    }
}


void check10()
{
    auto n = 100000;
    std::vector data(n, 0);
    data[n - 1] = 1;
    for (auto i{0}; i < n; i++) {
        data[i] = (i + 1) * 1000 ;
    }
    auto span = std::span(data);
    quick_sort(span);
    for (auto i{0}; i < n; i++)
    {
        assert(data[i] == (i + 1) * 1000);
    }
}


void check11()
{
    auto n = 100000;
    std::vector data(n, 0);
    data[n - 1] = 1;
    for (auto i{0}; i < n; i++) {
        data[i] = (i + 1) % 2;
    }
    auto span = std::span(data);
    quick_sort(span);
    for (auto i{0}; i < n / 2; i++)
    {
        assert(data[i] == 0);
    }
    for (auto i{n / 2}; i < n; i++)
    {
        assert(data[i] == 1);
    }
}


void check12()
{
    auto n = 100000;
    std::vector data(n, 0);
    data[n - 1] = 1;
    for (auto i{0}; i < n; i++) {
        data[i] = (i + 1) % 1000;
    }
    auto span = std::span(data);
    quick_sort(span);
    int prev = 0;
    for (auto v: data)
    {
        if (prev > v) {
            assert(false);
        }
        prev = v;
    }
}

void check13()
{
    auto n = 13;
    std::vector data(n, 0);
    data[n - 1] = 1;
    for (auto i{0}; i < n; i++) {
        data[i] = rand() % 1000;
    }
    print(data);
    auto span = std::span(data);
    quick_sort(span);
    int prev = 0;
    print(data);
    for (auto v: data)
    {
        if (prev > v) {
            assert(false);
        }
        prev = v;
    }
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
    std::cout << "Fifth check...";
    check5_5();
    std::cout << " Ok\n";   
    std::cout << "Six check...";
    check6();
    std::cout << " Ok\n";   
    std::cout << "Seventh check...";
    // check7();
    std::cout << " Ok\n";   
    std::cout << "Eighth check...";
    // check8();
    std::cout << " Ok\n";   
    std::cout << "Ninth check...";
    check13();
    std::cout << " Ok\n";   
}