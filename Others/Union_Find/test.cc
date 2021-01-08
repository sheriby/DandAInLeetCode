#include <iostream>

#include "union_find.hpp"

void test() {
    UnionFind u(3);
    u.union_(0, 1, 2.0);
    u.union_(1, 2, 3.0);

    double result = u.isConnected(0, 2);
    std::cout << "result: " << result << std::endl;
    result = u.isConnected(1, 0);
    std::cout << "result: " << result << std::endl;
    result = u.isConnected(2, 1);
    std::cout << "result: " << result << std::endl;
}

int main() {
    test();
    return 0;
}