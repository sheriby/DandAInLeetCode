#include "solution.cc"

void test() {
    Solution solution;
    vector<vector<int>> A{{0, 0, 1, 1}, {1, 0, 1, 0}, {1, 1, 0, 0}};
    for (auto v : A) {
        for (auto val : v) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
    int result = solution.matrixScore(A);
    std::cout << "Result: " << result << std::endl;
}

int main(int argc, char const *argv[]) {
    test();
    return 0;
}
