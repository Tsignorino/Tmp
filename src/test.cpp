#include <iostream>
#include <ranges>

extern void func1();

void func2() {
    auto check = [&](const int i) { return i & 1; };
    using namespace std::ranges::views;
    for (const int& v : iota(1) | take(10) | filter(check) | drop(2)) {
        std::cout << v << " ";
    }
    std::cout << "\n";
}

void func3() {
    for (constexpr auto arr = std::to_array({1, 2, 3, 5, 5}); const int& v : arr) {
        std::cout << v << "\n";
    }
}

void func() {
    // func1();
    func2();
    func3();
}