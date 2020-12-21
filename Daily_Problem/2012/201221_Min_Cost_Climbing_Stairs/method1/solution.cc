#include <unordered_map>
#include <vector>

using std::unordered_map;
using std::vector;

class Solution {
   public:
    // 典型的动态规划, 先使用最简单的递归加备忘录的方式实现
    int minCostClimbingStairs(vector<int>& cost) {
        return minCostClimbingStairs(cost, cost.size());
    }

   private:
    unordered_map<int, int> dp;
    int minCostClimbingStairs(vector<int>& cost, int index) {
        if (index <= 1) return 0;
        if (dp.count(index)) return dp[index];

        int result =
            std::min(minCostClimbingStairs(cost, index - 1) + cost[index - 1],
                     minCostClimbingStairs(cost, index - 2) + cost[index - 2]);
        dp[index] = result;
        return result;
    }
};