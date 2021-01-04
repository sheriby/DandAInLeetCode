class Solution {
   public:
    // 有点类似动态规划的思路，只和前两个状态有关，不必使用dp数组
    int fib(int n) {
        if (!n) return 0;
        int prev = 0;
        int result = 1;

        int tmp = 0;
        for (int i = 1; i < n; i++) {
            tmp = result;
            result += prev;
            prev = tmp;
        }

        return result;
    }
};