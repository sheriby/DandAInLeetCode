#include <vector>
using std::vector;

class Solution {
   public:
    // 使用图的深度优先搜索的方式
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> visited(n, false);
        int provinces = 0;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                visited[i] = true;
                dfs(isConnected, visited, i, n);
                provinces++;
            }
        }

        return provinces;
    };

   private:
    void dfs(vector<vector<int>>& isConnected, vector<bool>& visited, int i,
             int size) {
        for (int j = 0; j < size; j++) {
            if (isConnected[i][j] && !visited[j]) {
                visited[j] = true;
                dfs(isConnected, visited, j, size);
            }
        }
    }
};