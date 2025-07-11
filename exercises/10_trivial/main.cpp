#include "../exercise.h"

// READ: Trivial type <https://learn.microsoft.com/zh-cn/cpp/cpp/trivial-standard-layout-and-pod-types?view=msvc-170>

struct FibonacciCache {
    unsigned long long cache[16];
    int cached;
};

// TODO: 实现正确的缓存优化斐波那契计算
static unsigned long long fibonacci(FibonacciCache &fib, int i) {
    // 处理负数索引
    if (i < 0) return 0;
    
    // 确保前两个值已初始化（斐波那契数列的基本情况）
    if (fib.cached == 0) {
        fib.cache[0] = 0;
        fib.cached = 1;
    }
    if (fib.cached == 1) {
        fib.cache[1] = 1;
        fib.cached = 2;
    }
    
    // 计算并缓存直到i的所有值（确保不越界）
    for (; fib.cached <= i && fib.cached < 16; ++fib.cached) {
        fib.cache[fib.cached] = fib.cache[fib.cached - 1] + fib.cache[fib.cached - 2];
    }
    
    // 返回结果（越界时返回0或其他默认值）
    return i < 16 ? fib.cache[i] : 0;
}

int main(int argc, char **argv) {
    // TODO: 初始化缓存结构体，使计算正确
    // NOTICE: C/C++ 中，读取未初始化的变量（包括结构体变量）是未定义行为
    // READ: 初始化的各种写法 <https://zh.cppreference.com/w/cpp/language/initialization>
    FibonacciCache fib = {{0,1},2};
    ASSERT(fibonacci(fib, 10) == 55, "fibonacci(10) should be 55");
    std::cout << "fibonacci(10) = " << fibonacci(fib, 10) << std::endl;
    return 0;
}
