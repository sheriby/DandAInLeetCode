#include <iostream>

#include "solution.cc"

void printImg(vector<vector<int>> img) {
    for (auto&& v : img) {
        for (auto&& val : v) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
}

void test() {
    Solution s;
    vector<vector<int>> img{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    printImg(img);
    s.rotate(img);
    printImg(img);
}

int main(int argc, char const* argv[]) {
    test();
    return 0;
}
