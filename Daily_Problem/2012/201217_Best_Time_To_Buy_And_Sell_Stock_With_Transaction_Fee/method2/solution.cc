#include <vector>
using std::vector;

class Solution {
   public:
    // 使用动态规划
    int maxProfit(vector<int>& prices, int fee) {
        int size = prices.size();
        vector<vector<int>> dp(size, vector<int>(2));
        // dp[i][0] 表示第i天没有股票的最大利润
        // dp[i][1] 表示第i天持有股票的最大利润
        dp[0][0] = 0;
        dp[0][1] = -prices[0];
        for (size_t i = 1; i < size; i++) {
            dp[i][0] = std::max(dp[i - 1][0], dp[i - 1][1] + prices[i] - fee);
            dp[i][1] = std::max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
        }

        return dp[size - 1][0];
    }
};