#include "solution.cc"

void test() {
    MedianFinder m;
    m.addNum(6);
    m.addNum(1);
    m.addNum(3);
    m.addNum(4);
    m.addNum(1);
    m.addNum(6);
    double res = m.findMedian();
    std::cout << res << std::endl;
}

int main(int argc, char const *argv[]) {
    test();
    return 0;
}

/*
执行结果：通过
执行用时 :
    156 ms, 在所有 C++ 提交中击败了82.29%的用户
内存消耗 :
    42.7 MB, 在所有 C++ 提交中击败了23.24%的用户
*/