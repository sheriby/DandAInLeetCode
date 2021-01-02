#include <iostream>

#include "sparse_table.hpp"

void test() {
    vector<int> v{1, 3, 5, 2, 4, 6, 5, 7, 9, 4, 3, 2};
    sparse_table st(v);
    int result = st.RMQ(2, 9);
    std::cout << "result: " << result << std::endl;
}

int main() {
    test();
    return 0;
}