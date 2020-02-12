#include "solution.cc"

void test() {
    vector<int> g{1, 3, 5, 7, 9};
    vector<int> s{3, 2, 1, 4, 6};

    int res = Solution().findContentChildren(g, s);
    std::cout << res << std::endl;
}

int main(int argc, char const *argv[]) {
    test();
    return 0;
}

/*
执行结果：通过
执行用时 :
    28 ms, 在所有 C++ 提交中击败了99.89%的用户
内存消耗 :
    10.3 MB, 在所有 C++ 提交中击败了54.14%的用户
*/
