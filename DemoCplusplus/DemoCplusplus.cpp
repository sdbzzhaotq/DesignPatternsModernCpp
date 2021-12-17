#include <iostream>
#include <stack>

void foo(int i) { std::cout << "int" << std::endl; }
void foo(char* pc) { std::cout << "pointer" << std::endl; }


int main() {
    /**/
    int id = 0;
    auto f = [id]() mutable {
        std::cout << "id: " << id << std::endl;
        ++id;
    };
    /*不能讲这段代码写到main函数之外，那样的话id就是静态存储持续时间的变量，它不需要被捕获*/

    int tobefound = 5;
    auto lambda1 = [tobefound]( int val ) { return val == tobefound; };

    id = 42;
    f();
    f();
    f();
    std::stack<int> a{};
    std::cout << id << std::endl;
    foo(NULL);
    foo(nullptr);
}
