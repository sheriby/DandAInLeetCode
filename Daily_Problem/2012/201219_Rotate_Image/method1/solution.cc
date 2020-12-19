#include <vector>
using std::vector;

class Solution {
   public:
    // 先横向对折交换，后沿主对角线交换
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int top = 0, bottom = n - 1;
        while (top < bottom) {
            std::swap(matrix[top++], matrix[bottom--]);
        }

        for (size_t i = 1; i < n; i++) {
            for (size_t j = 0; j < i; j++) {
                matrix[i][j] ^= matrix[j][i] ^= matrix[i][j] ^= matrix[j][i];
            }
        }
    }
};