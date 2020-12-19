#include <vector>
using std::vector;

class Solution {
   public:
    // 自己乱搞的方法，基本上就是贪心的思想，在后一天买入的时候思考前一天股票是否该卖
    // 不过思路写的可能有点乱
    int maxProfit(vector<int>& prices, int fee) {
        int size = prices.size();
        if (size < 2) return 0;
        if (size == 2) return std::max(prices[1] - prices[0] - fee, 0);

        int profit = 0;

        vector<int> buy(size, 0);
        vector<int> sell(size, 0);
        buy[0] = -prices[0];
        for (size_t i = 1; i < size; i++) {
            if (-prices[i] > buy[i - 1]) {
                profit += sell[i - 1];
                buy[i] = -prices[i];
                sell[i] = 0;
                continue;
            }

            sell[i] = buy[i - 1] + prices[i] - fee;

            if (sell[i - 1] - sell[i] >= fee) {
                profit += sell[i - 1];
                buy[i] = -prices[i];
                sell[i] = 0;
            } else {
                sell[i] = std::max(sell[i], sell[i - 1]);
                buy[i] = buy[i - 1];
            }
        }
        if (sell.back() > 0) {
            profit += sell.back();
        }

        return profit;
    }
};