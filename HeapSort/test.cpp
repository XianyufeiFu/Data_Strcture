#include <algorithm>
#include "HeapSort.h"
#include <iostream>
#include <cstdlib>
#include <random>
#include <chrono>

int main(){
    HeapSort<int> a;
    srand((unsigned)time(NULL));
    // a.ascending_queue();
    a.random_generator();
    // a.printvector();
    HeapSort b = a;
    auto start1 = std::chrono::high_resolution_clock::now();
    a.sort();
    auto end1 = std::chrono::high_resolution_clock::now();
    auto duration1 = std::chrono::duration_cast<std::chrono::milliseconds>(end1 - start1);
    auto start2 = std::chrono::high_resolution_clock::now();
    b.std_sort();
    auto end2 = std::chrono::high_resolution_clock::now();
    auto duration2 = std::chrono::duration_cast<std::chrono::milliseconds>(end2 - start2);
    std::cout << a.check() << std::endl;
    a.printvector();
    // std::cout << a.v1 << std::endl;
    std::cout << "Function took " << duration1.count() << " milliseconds to execute." << std::endl;
    std::cout << "Function took " << duration2.count() << " milliseconds to execute." << std::endl;
    std::cout << std::endl;

    a.ascending_queue();
    b = a;
    auto start3 = std::chrono::high_resolution_clock::now();
    a.sort();
    auto end3 = std::chrono::high_resolution_clock::now();
    auto duration3 = std::chrono::duration_cast<std::chrono::milliseconds>(end3 - start3);
    auto start4 = std::chrono::high_resolution_clock::now();
    b.std_sort();
    auto end4 = std::chrono::high_resolution_clock::now();
    auto duration4 = std::chrono::duration_cast<std::chrono::milliseconds>(end4 - start4);
    std::cout << a.check() << std::endl;
    a.printvector();
    // std::cout << a.v1 << std::endl;
    std::cout << "Function took " << duration3.count() << " milliseconds to execute." << std::endl;
    std::cout << "Function took " << duration4.count() << " milliseconds to execute." << std::endl;
    std::cout << std::endl;

    a.descending_queue();
    b = a;
    auto start5 = std::chrono::high_resolution_clock::now();
    a.sort();
    auto end5 = std::chrono::high_resolution_clock::now();
    auto duration5 = std::chrono::duration_cast<std::chrono::milliseconds>(end5 - start5);
    auto start6 = std::chrono::high_resolution_clock::now();
    b.std_sort();
    auto end6 = std::chrono::high_resolution_clock::now();
    auto duration6 = std::chrono::duration_cast<std::chrono::milliseconds>(end6 - start6);
    std::cout << a.check() << std::endl;
    a.printvector();
    // std::cout << a.v1 << std::endl;
    std::cout << "Function took " << duration5.count() << " milliseconds to execute." << std::endl;
    std::cout << "Function took " << duration6.count() << " milliseconds to execute." << std::endl;
    std::cout << std::endl;

    a.repetitive_queue();
    b = a;
    auto start7 = std::chrono::high_resolution_clock::now();
    a.sort();
    auto end7 = std::chrono::high_resolution_clock::now();
    auto duration7 = std::chrono::duration_cast<std::chrono::milliseconds>(end7 - start7);
    auto start8 = std::chrono::high_resolution_clock::now();
    b.std_sort();
    auto end8 = std::chrono::high_resolution_clock::now();
    auto duration8 = std::chrono::duration_cast<std::chrono::milliseconds>(end8 - start8);
    std::cout << a.check() << std::endl;
    a.printvector();
    // std::cout << a.v1 << std::endl;
    std::cout << "Function took " << duration7.count() << " milliseconds to execute." << std::endl;
    std::cout << "Function took " << duration8.count() << " milliseconds to execute." << std::endl;

    while(1);

    return 0;
}