#include <unordered_map>
using std::unordered_map;

class Solution {
   public:
    // 使用动态规划的备忘录的形式配合递归，当然也可以使用迭代这样简单高效的方式，如方法二
    int numTrees(int n) {
        if (numTreesMap.count(n)) {
            return numTreesMap[n];
        }
        int res = 2 * numTrees(n - 1);
        for (int i = 1; i < n - 1; i++) {
            res += numTrees(n - i - 1) * numTrees(i);
        }

        numTreesMap[n] = res;

        return res;
    }

    Solution() {
        // 初始化map，也就是初始条件，可以使用0，1作为初始条件，但是我感觉1, 2明显更好
        numTreesMap[1] = 1;
        numTreesMap[2] = 2;
    }

   private:
    // 保存得到结果
    unordered_map<int, int> numTreesMap;
};