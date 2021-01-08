#include <iostream>

#include "solution.cc"

void test() {
    Solution s;
    vector<vector<string>> e{{"a", "b"}, {"b", "c"}};
    vector<double> v{2.0, 3.0};
    vector<vector<string>> q{{"a", "c"}, {"b", "a"}, {"c", "x"}};
    auto result = s.calcEquation(e, v, q);
    for (auto&& v : result) {
        std::cout << v << " ";
    }
    std::cout << std::endl;
}

int main() {
    test();
    return 0;
}