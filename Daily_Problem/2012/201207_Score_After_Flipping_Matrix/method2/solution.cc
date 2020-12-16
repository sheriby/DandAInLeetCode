#include <iostream>
#include <vector>
using std::vector;

static const auto __ = [] {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();

class Solution {
   public:
    // 贪心算法的时候不必修改原来矩阵, 只需计算每一行/列对总分的贡献即可
    // 时间复杂度: O(MN)
    // 空间复杂度: O(1)
    int matrixScore(vector<vector<int>>& A) {
        int rowSize = A.size();
        int columnSize = A[0].size();
        int result = rowSize * (1 << (columnSize - 1));

        for (size_t i = 1; i < columnSize; i++) {
            int oneNums = 0;
            for (size_t j = 0; j < rowSize; j++) {
                if (A[j][0])
                    oneNums += A[j][i];
                else
                    oneNums += 1 - A[j][i];
            }
            oneNums =
                oneNums > (rowSize - oneNums) ? oneNums : (rowSize - oneNums);
            result += oneNums * (1 << (columnSize - i - 1));
        }

        return result;
    }
};