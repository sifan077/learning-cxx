#include "../exercise.h"

struct A {
    static int num_a;

    A() {
        ++num_a;
    }

    virtual ~A() {  // 必须是虚析构函数
        --num_a;
    }

    virtual char name() const {
        return 'A';
    }
};

struct B final : public A {
    static int num_b;

    B() {
        ++num_b;
    }

    ~B() {
        --num_b;
    }

    char name() const final {
        return 'B';
    }
};

// 静态字段初始化
int A::num_a = 0;
int B::num_b = 0;

// 因为B继承A，A的析构函数必须为虚函数,A的构造函数会执行

int main(int argc, char **argv) {
    auto a = new A;
    auto b = new B;
    ASSERT(A::num_a == 2, "Fill in the correct value for A::num_a");
    ASSERT(B::num_b == 1, "Fill in the correct value for B::num_b");
    ASSERT(a->name() == 'A', "Fill in the correct value for a->name()");
    ASSERT(b->name() == 'B', "Fill in the correct value for b->name()");

    delete a;
    delete b;
    ASSERT(A::num_a == 0, "Every A was destroyed");
    ASSERT(B::num_b == 0, "Every B was destroyed");

    A *ab = new B;
    ASSERT(A::num_a == 1, "Fill in the correct value for A::num_a");
    ASSERT(B::num_b == 1, "Fill in the correct value for B::num_b");
    ASSERT(ab->name() == 'B', "Fill in the correct value for ab->name()");

    B &bb = dynamic_cast<B&>(*ab);  // 安全向下转型
    ASSERT(bb.name() == 'B', "Fill in the correct value for bb->name()");

    delete ab;
    ASSERT(A::num_a == 0, "Every A was destroyed");
    ASSERT(B::num_b == 0, "Every B was destroyed");

    return 0;
}
