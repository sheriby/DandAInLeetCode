#include "solution.cc"
#include <iostream>

void testRes(int res, int ans) {
    std::cout << "res => " << res << std::endl;
    std::cout << "ans => " << ans << std::endl;
    if (res == ans) {
        std::cout << "Test Success!" << std::endl;
    } else {
        std::cout << "Test Failure!" << std::endl;
    }
}

void test() {
    vector<int> arr{1, 2, 3, 4, 5, 6, 7};
    int k = 3;
    int res = Solution().findKthLargest(arr, k);
    testRes(res, 5);
}

int main(int argc, char const *argv[]) {
    test();
    return 0;
}

/*
执行结果：通过
执行用时 :
    12 ms, 在所有 C++ 提交中击败了83.07%的用户
内存消耗 :
    9.5 MB, 在所有 C++ 提交中击败了25.36%的用户
*/
