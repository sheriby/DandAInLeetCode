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
    // 使用贪心算法，先变行使得所有的行的第一位都变成1，
    // 然后变列使得所有的列的1多于半数
    // 这里使用的算法，修改了原矩阵，不是很好
    // 时间复杂度: O(MN)
    // 空间复杂度: O(1)
    int matrixScore(vector<vector<int>>& A) {
        for (size_t i = 0; i < A.size(); i++) {
            if (A[i][0] == 0) flippingRow(A[i]);
        }

        for (size_t i = 1; i < A[0].size(); i++) {
            if (isColumnFlipping(A, i)) flippingColumn(A, i);
        }

        int result = 0;
        for (auto row : A) {
            result += rowScore(row);
        }

        return result;
    }

   private:
    void flippingRow(vector<int>& row) {
        for (size_t i = 0; i < row.size(); i++) {
            row[i] = row[i] == 0 ? 1 : 0;
        }
    }

    void flippingColumn(vector<vector<int>>& A, int column) {
        for (size_t i = 0; i < A.size(); i++) {
            A[i][column] = A[i][column] == 0 ? 1 : 0;
        }
    }

    bool isColumnFlipping(vector<vector<int>>& A, int column) {
        int count = 0;
        for (size_t i = 0; i < A.size(); i++) {
            if (A[i][column]) count++;
        }
        if (count <= A.size() / 2)
            return true;
        else
            return false;
    }

    int rowScore(vector<int>& row) {
        int result = 0;
        for (size_t i = 0; i < row.size(); i++) {
            result *= 2;
            result += row[i];
        }
        return result;
    }
};