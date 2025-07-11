#include "../exercise.h"

// READ: 有 cv 限定符的成员函数 <https://zh.cppreference.com/w/cpp/language/member_functions>

struct Fibonacci {
    int numbers[11];
    // TODO: 修改方法签名和实现，使测试通过

    /*
        const对象只能调用const方法：要是成员函数不会对对象的数据成员进行修改，就应当把它声明为const方法。
        返回const引用：由于FIB是const对象，返回其成员的引用时也得用const修饰，以此保持类型的一致性。
    */
    int  get(int i) const{
        return numbers[i];
    }
};

int main(int argc, char **argv) {
    Fibonacci constexpr FIB{{0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55}};
    ASSERT(FIB.get(10) == 55, "fibonacci(10) should be 55");
    std::cout << "fibonacci(10) = " << FIB.get(10) << std::endl;
    return 0;
}
