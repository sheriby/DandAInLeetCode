#include "solution.cc"

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
    vector<int> arr{4, 10, 3, 6, 7, 8};
    int k = 3; // 6 - 3 + 1
    int res = Solution().findKthLargest(arr, k);
    testRes(res, 7);
}

int main(int argc, char const *argv[]) {
    test();
    return 0;
}

/*
执行结果：通过
执行用时 :
    32 ms, 在所有 C++ 提交中击败了28.47%的用户
内存消耗 :
    9.9 MB, 在所有 C++ 提交中击败了9.92%的用户
*/
