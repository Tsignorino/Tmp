//
// Created by signorino on 24-6-5.
//
#include <iostream>
#include <vector>

extern void func();

int main() {
    func();

    for (constexpr std::vector vec{1, 2, 3}; const int& v : vec) {
        std::cout << v << " ";
    }
    std::cout << "Hello";

    return 0;
}