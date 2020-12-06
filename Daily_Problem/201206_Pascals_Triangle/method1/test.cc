#include "solution.cc"
using std::cout;
using std::endl;

void printVectorVector(vector<vector<int>> vv) {
    for (auto v : vv) {
        for (auto val : v) {
            cout << val << " ";
        }
        cout << endl;
    }
}

void test() {
    Solution solution;
    vector<vector<int>> result = solution.generate(5);
    printVectorVector(result);
}

int main(int argc, char const *argv[]) {
    test();
    return 0;
}
