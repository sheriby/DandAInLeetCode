#include <vector>
using std::vector;

class Solution {
   public:
    // 动态规划，使用迭代的方式
    int numTrees(int n) {
        // 这里相当于使用的是一个map，数组的下标就是key
        vector<int> resultMap(n + 1, 0);
        // 这里使用0, 1作为初始条件比较好
        resultMap[0] = 1;
        resultMap[1] = 1;

        for (int i = 2; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                resultMap[i] += resultMap[j] * resultMap[i - j - 1];
            }
        }
        
        return resultMap[n];
    }
};