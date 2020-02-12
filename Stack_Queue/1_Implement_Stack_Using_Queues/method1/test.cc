#include "solution.cc"

void test() {
    MyStack s;
    s.push(3);
    s.push(2);
    std::cout << s.pop() << std::endl;
    std::cout << s.empty() << std::endl;
    std::cout << s.top() << std::endl;
    s.push(5);
    std::cout << s.top() << std::endl; 
}

int main(int argc, char const *argv[]) {
    test();
    return 0;
}

/*
执行结果：通过
执行用时 :
    0 ms, 在所有 C++ 提交中击败了100.00%的用户
内存消耗 :
    8.9 MB, 在所有 C++ 提交中击败了15.21%的用户
*/