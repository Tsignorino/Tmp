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

    // �հ������Ͳ��ܱ�ָ���������� auto �ἰ
    // C++14 ��lambda ������Ĭ��ʵ��
    auto func1 = [](const int i = 6) { return i + 4; };
    std::cout << "func1: " << func1() << '\n';

    // �����пɵ��ö�����ͬ���հ��ܿ��Ա����� std::function ֮��
    // ������ܴ�������Ҫ�Ŀ�����
    const std::function<int(int)> func2 = [](const int i) { return i + 4; };
    std::cout << "func2: " << func2(6) << '\n';

    std::cout << "ģ�µݹ� lambda ���ã�\n쳲���������";
    auto nth_fibonacci = [](const int n) {
        std::function<int(int, int, int)> fib = [&](int n, int a, int b) {
            return n ? fib(n - 1, a + b, a) : b;
        };
        return fib(n, 0, 1);
    };

    for (int i{1}; i <= fib_max; ++i) {
        std::cout << nth_fibonacci(i) << (i < fib_max ? ", " : "\n");
    }

    //    std::cout << "��һ�� lambda �ݹ鷽����\n쳲���������";
    //    auto nth_fibonacci = [](auto&& self, int n, int a = 0, int b = 1) {
    //        return n ? self(self, n - 1, a + b, a) : b;
    //    };
    //    for (int i{1}; i <= fib_max; ++i) {
    //        std::cout << nth_fibonacci(nth_fibonacci, i) << (i < fib_max ? ", " : "\n");
    //    }

#ifdef __cpp_explicit_this_parameter
    std::cout << "C++23 �� lambda �ݹ鷽����\n";
    auto nth_fibonacci3 = [](this auto self, int n, int a = 0, int b = 1) {
        return n ? self(n - 1, a + b, a) : b;
    };

    for (int i{1}; i <= fib_max; ++i) {
        std::cout << nth_fibonacci3(i) << (i < fib_max ? ", " : "\n");
    }
#endif
}