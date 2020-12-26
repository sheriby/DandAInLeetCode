#include <iostream>
#include <vector>
using std::vector;

class Solution {
   public:
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
        for (size_t i = 0; i < matrix.size(); i++) {
            for (size_t j = 0; j < matrix[0].size(); j++) {
                int area = computeArea(left, i, j);
                max = area > max ? area : max;
            }
        }

        return max;
    }

   private:
    // 以matrix[i][j]作为右下角的矩形的最大面积
    int computeArea(vector<vector<int>>& left, int i, int j) {
        int result = 0;
        int x = left[0].size(), y = 0;

        while (true) {
            if (i < 0) break;
            if (left[i][j] < x) x = left[i][j];
            if (!x) break;
            y++;
            if (x * y > result) result = x * y;
            i--;
        }

        return result;
    }
};