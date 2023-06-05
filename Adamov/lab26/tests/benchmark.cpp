#include "../include/stack.hpp"
#include <bits/chrono.h>
#include <iostream>
#include <stack>
#include <chrono>

void benchmark() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int64_t comparsion_num = 100000000;
    Stack<int64_t> my_stk;
    std::stack<int64_t> stk;

    std::cout << "Push:" << std::endl;
    std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now(); 
    for (int64_t i = 0; i < comparsion_num; ++i) {
        stk.push(i);
    }
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now(); 
    std::cout << "STL: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << " ms" << std::endl;

    start = std::chrono::steady_clock::now(); 
    for (int64_t i = 0; i < comparsion_num; ++i) {
        my_stk.push(i);
    }
    end = std::chrono::steady_clock::now(); 
    std::cout << "Ours: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << " ms" << std::endl;

    std::cout << "Pop:" << std::endl;
    start = std::chrono::steady_clock::now(); 
    for (int64_t i = 0; i < comparsion_num; ++i) {
        stk.pop();
    }
    end = std::chrono::steady_clock::now(); 
    std::cout << "STL: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << " ms" << std::endl;

    start = std::chrono::steady_clock::now(); 
    for (int64_t i = 0; i < comparsion_num; ++i) {
        my_stk.pop();
    }
    end = std::chrono::steady_clock::now(); 
    std::cout << "Ours: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << " ms" << std::endl;
}
