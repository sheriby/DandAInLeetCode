#include <vector>

#include "union_find_without_weight.hpp"
using std::vector;

class Solution {
   public:
    // 使用不带权值的并查集来做比较的直观
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        UnionFind u(n);
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (isConnected[i][j]) u.union_(i, j);
            }
        }

        return u.numberOfSet();
    }
};