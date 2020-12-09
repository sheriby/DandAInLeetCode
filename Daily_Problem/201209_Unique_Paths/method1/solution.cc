#include <vector>
using std::vector;

class Solution {
   public:
    // 感觉则也是一个非常典型的递归问题
    // 为了防止多余计算，我们使用一个二维数组作为备忘录
    int uniquePaths(int m, int n) {
        vector<vector<int>> map(m, vector<int>(n, -1));
        return uniquePaths(m, n, 1, 1, map);
    }

   private:
    int uniquePaths(int m, int n, int curm, int curn,
                    vector<vector<int>>& map) {
        if (map[curm - 1][curn - 1] != -1) return map[curm - 1][curn - 1];
        if (curm == m || curn == n) return 1;

        int result = uniquePaths(m, n, curm + 1, curn, map) +
                     uniquePaths(m, n, curm, curn + 1, map);

        map[curm - 1][curn - 1] = result;
        return result;
    }
};
