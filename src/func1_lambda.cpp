//
// Created by signorino on 2024/3/1.
//

#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>
//#include <ranges>

void func1() {
    constexpr int fib_max{8};

    std::vector c{1, 2, 3, 4, 5, 6, 7};
    std::erase_if(c, [](const int n) { return n < 5; });
    std::cout << "c: ";
    std::ranges::for_each(c, [](const int i) { std::cout << i << ' '; });
    std::cout << '\n';

    // 闭包的类型不能被指名，但可用 auto 提及
    // C++14 起，lambda 可以有默认实参
    auto func1 = [](const int i = 6) { return i + 4; };
    std::cout << "func1: " << func1() << '\n';

    // 与所有可调用对象相同，闭包能可以被捕获到 std::function 之中
    // （这可能带来不必要的开销）
    const std::function<int(int)> func2 = [](const int i) { return i + 4; };
    std::cout << "func2: " << func2(6) << '\n';

    std::cout << "模仿递归 lambda 调用：\n斐波那契数：";
    auto nth_fibonacci = [](const int n) {
        std::function<int(int, int, int)> fib = [&](int n, int a, int b) {
            return n ? fib(n - 1, a + b, a) : b;
        };
        return fib(n, 0, 1);
    };

    for (int i{1}; i <= fib_max; ++i) {
        std::cout << nth_fibonacci(i) << (i < fib_max ? ", " : "\n");
    }

    //    std::cout << "另一种 lambda 递归方案：\n斐波那契数：";
    //    auto nth_fibonacci = [](auto&& self, int n, int a = 0, int b = 1) {
    //        return n ? self(self, n - 1, a + b, a) : b;
    //    };
    //    for (int i{1}; i <= fib_max; ++i) {
    //        std::cout << nth_fibonacci(nth_fibonacci, i) << (i < fib_max ? ", " : "\n");
    //    }

#ifdef __cpp_explicit_this_parameter
    std::cout << "C++23 的 lambda 递归方案：\n";
    auto nth_fibonacci3 = [](this auto self, int n, int a = 0, int b = 1) {
        return n ? self(n - 1, a + b, a) : b;
    };

    for (int i{1}; i <= fib_max; ++i) {
        std::cout << nth_fibonacci3(i) << (i < fib_max ? ", " : "\n");
    }
#endif
}