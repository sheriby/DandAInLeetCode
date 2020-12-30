#include <iostream>

#include "solution.cc"

void test() {
    Solution s;
    vector<string> strs{"aab", "aba", "bab", "bba"};
    auto res = s.groupAnagrams(strs);

    for (auto r : res) {
        for (auto v : r) {
            std::cout << v << " ";
        }
        std::cout << std::endl;
    }
}

int main(int argc, char const *argv[]) {
    test();
    return 0;
}
