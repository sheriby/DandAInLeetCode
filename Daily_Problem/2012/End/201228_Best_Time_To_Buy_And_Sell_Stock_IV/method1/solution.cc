#include <limits.h>

#include <algorithm>
#include <vector>

using std::vector;

class Solution {
   public:
    // 使用动态规划算法
    int maxProfit(int k, vector<int>& prices) {
        if (prices.empty()) {
            return 0;
        }

        int n = prices.size();
        k = std::min(k, n / 2);
        vector<vector<int>> buy(n, vector<int>(k + 1));
        vector<vector<int>> sell(n, vector<int>(k + 1));

        buy[0][0] = -prices[0];
        sell[0][0] = 0;
        for (int i = 1; i <= k; ++i) {
            buy[0][i] = sell[0][i] = INT_MIN / 2;
        }

        for (int i = 1; i < n; ++i) {
            buy[i][0] = std::max(buy[i - 1][0], sell[i - 1][0] - prices[i]);
            for (int j = 1; j <= k; ++j) {
                buy[i][j] = std::max(buy[i - 1][j], sell[i - 1][j] - prices[i]);
                sell[i][j] =
                    std::max(sell[i - 1][j], buy[i - 1][j - 1] + prices[i]);
            }
        }

        return *std::max_element(sell[n - 1].begin(), sell[n - 1].end());
    }
};