#include <iostream>
using std::cout;
using std::endl;

#include "solution.cc"

void test() {
    Solution s;
    bool result = s.isIsomorphic("ab", "aa");
    cout << "Result: " << result << endl;
}

int main(int argc, char const *argv[]) {
    test();
    return 0;
}
