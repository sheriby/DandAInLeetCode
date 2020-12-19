#include <vector>
using std::vector;

class Solution {
   public:
    // 官方的贪心算法, 还是比较容易理解的
    int maxProfit(vector<int>& prices, int fee) {
        int size = prices.size();
        int buy = prices[0] + fee;

        int profit = 0;
        for (size_t i = 1; i < size; i++) {
            if (prices[i] + fee < buy) {
                buy = prices[i] + fee;
            } else if (prices[i] > buy) {
                profit += prices[i] - buy;
                buy = prices[i];
            }
        }
    }
};