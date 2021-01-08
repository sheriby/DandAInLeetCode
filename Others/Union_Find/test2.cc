#include <iostream>

#include "union_find_without_weight.hpp"

void test() {
    UnionFind u(4);
    u.union_(0, 1);
    u.union_(1, 2);
    bool result = u.isConnected(0, 2);
    std::cout << "result: " << result << std::endl;
    result = u.isConnected(1, 3);
    std::cout << "result: " << result << std::endl;
    std::cout << "u.numberOfSet(): " << u.numberOfSet() << std::endl;
}

int main() {
    test();
    return 0;
}