#include <vector>

using std::vector;

class Solution {
   public:
    // 使用递推的方法实现
    // 这种方法似乎更加的简单哈哈哈
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size() + 1);
        for (size_t i = 2; i < cost.size(); i++) {
            dp[i] = std::min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
        }

        return dp[cost.size()];
    }
};