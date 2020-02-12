#include "solution.cc"

void test() {
    MedianFinder m;
    // m.addNum(1);
    // m.addNum(2);
    // m.addNum(3);
    // m.addNum(4);
    // m.addNum(5);
    // m.addNum(6);
    // m.addNum(7);
    // m.addNum(0);
    // m.addNum(-1);
    // m.addNum(8);
    // m.addNum(7);
    m.addNum(12);
    double res = m.findMedian();
    std::cout << res << std::endl;
    m.addNum(10);
    res = m.findMedian();
    std::cout << res << std::endl;
    m.addNum(10);
    res = m.findMedian();
    std::cout << res << std::endl;
    m.addNum(15);
    res = m.findMedian();
    std::cout << res << std::endl;
    m.addNum(11);
    res = m.findMedian();
    std::cout << res << std::endl;

    m.addNum(8);
    res = m.findMedian();
    std::cout << res << std::endl;

    m.addNum(17);
    res = m.findMedian();
    std::cout << res << std::endl;
}

int main(int argc, char const *argv[]) {
    test();
    return 0;
}

/*
执行结果：通过
执行用时 :
    160 ms, 在所有 C++ 提交中击败了80.54%的用户
内存消耗 :
    45 MB, 在所有 C++ 提交中击败了5.10%的用户
*/