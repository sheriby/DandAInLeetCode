#include <iostream>
#include <stack>
#include <vector>

using std::stack;
using std::vector;

class Solution {
   public:
    // 使用单调栈的方式
    int maximalRectangle(vector<vector<char>>& matrix) {
        vector<vector<int>> left(matrix.size(), vector<int>(matrix[0].size()));
        for (size_t i = 0; i < matrix.size(); i++) {
            int one = 0;
            for (size_t j = 0; j < matrix[0].size(); j++) {
                if (matrix[i][j] == '1')
                    one++;
                else
                    one = 0;
                left[i][j] = one;
            }
        }

        int max = 0;
        // 对每一列进行求最大值操作
        for (size_t i = 0; i < matrix[0].size(); i++) {
            vector<int> up(matrix.size(), 0), down(matrix.size(), 0);
            stack<int> stk;
            for (size_t j = 0; j < matrix.size(); j++) {
                while (!stk.empty() && left[stk.top()][i] >= left[j][i]) {
                    stk.pop();
                }
                up[j] = stk.empty() ? -1 : stk.top();
                stk.push(j);
            }

            stk = stack<int>();

            for (int j = matrix.size() - 1; j >= 0; j--) {
                while (!stk.empty() && left[stk.top()][i] >= left[j][i]) {
                    stk.pop();
                }
                down[j] = stk.empty() ? matrix.size() : stk.top();
                stk.push(j);
            }

            int ret;
            for (size_t j = 0; j < matrix.size(); j++) {
                int ret = left[j][i] * (down[j] - up[j] - 1);
                max = ret > max ? ret : max;
            }
        }

        return max;
    }
};