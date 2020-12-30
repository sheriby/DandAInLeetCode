#include <iostream>

#include "solution.cc"

void test() {
    Solution s;
    vector<int> nums{1, 3, 4, 6, 2, 3};
    bool result = s.containsDuplicate(nums);
    std::cout << "Result: " << result << std::endl;
}

int main(int argc, char const *argv[]) {
    test();
    return 0;
}
