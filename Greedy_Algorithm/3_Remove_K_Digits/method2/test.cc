#include "solution.cc"
#include <iostream>

void test() {
    Solution solve;
    std::string result = solve.removeKdigits("1432219", 3);
    std::cout << "result is " << result << std::endl;
    std::string result2 = solve.removeKdigits("100200", 1);
    std::cout << "result is " << result2 << std::endl;
}

int main(int argc, char *argv[]) {
    test();
    return 0;
}

/*
执行结果：通过
执行用时 :
    4 ms, 在所有 C++ 提交中击败了94.71%的用户
内存消耗 :
    8.5 MB, 在所有 C++ 提交中击败了100%的用户
*/
