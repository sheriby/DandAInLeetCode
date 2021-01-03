#include <iostream>

#include "segment_tree.hpp"

void test() {
    vector<int> v{1, 6, 3, 4, 6, 5, 4, 8, 2};
    segment_tree seg(v);
    int result = seg.query(1, 8);
    std::cout << "result: " << result << std::endl;
    seg.update(7, 11);
    result = seg.query(1, 8);
    std::cout << "result: " << result << std::endl;
}

int main() {
    test();
    return 0;
}