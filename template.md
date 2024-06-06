##### C++ 模板 #####

## 控制代码生成，实现泛型

```cpp

#define add(T) _ADD_IMPL_##T

#define ADD_IMPL(T)              \
T _ADD_IMPL_##T (T a, T b) {     \
    return a + b;                \
}

ADD_IMPL(int);
ADD_IMPL(float);

int main() {
    add(int)(1, 2);
    add(float)(1.0f, 2.0f);
}

```

```cpp

template<typename T>
T add(T a, T b) {
    return a + b;
}

template int add<>(int, int); // 显式实例化

int main() {
    add<int>(1, 2); // 显式指定模板参数 T
    add(1, 2); // 自动推导模板参数 T
    add(1.0f, 2.0f); // 自动推导并且隐式实例化
}

```

## 做泛型约束

```cpp

struct A{};

template<typename T>
void print1(T x) {
    std::cout << x << std::endl;
}

template<typename T>
// requires requires (T x) { std::cout << x; } 
// C++20加入的requires语法，意思就是要求std::cout << x`是合法的。
void print2(T x) {
    print1(x);
    std::cout << x << std::endl;
}


int main() {
    print2(A{});
}

template<typename T, typename = decltype(std::cout << std::declval<T>())> 
void print2(T x) {
    print1(x);
    std::cout << x << std::endl;
}

```

## 编译器计算

## 对类型做计算