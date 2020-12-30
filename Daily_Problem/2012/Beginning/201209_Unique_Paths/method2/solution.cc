#include <vector>
using std::vector;

class Solution {
   public:
    // 除了自顶向下的备忘录，我们还可以使用自底向上的递推
    int uniquePaths(int m, int n) {
        vector<vector<int>> map(m, vector<int>(n, 1));

        for (int i = m - 2; i >= 0; i--) {
            for (int j = n - 2; j >= 0; j--) {
                map[i][j] = map[i + 1][j] + map[i][j + 1];
            }
        }
        return map[0][0];
    }
};
