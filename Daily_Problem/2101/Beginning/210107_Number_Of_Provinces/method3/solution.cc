#include <queue>
#include <vector>

using std::queue;
using std::vector;

class Solution {
   public:
    // 同样可以使用广度优先搜索，不过需要使用队列，不可用递归实现了
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> visited(n, false);
        queue<int> q;
        int provinces = 0;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                q.push(i);
                while (!q.empty()) {
                    int t = q.front();
                    q.pop();
                    visited[t] = true;
                    for (int j = 0; j < n; j++) {
                        if (isConnected[t][j] && !visited[j]) {
                            visited[j] = true;
                            q.push(j);
                        }
                    }
                }
                provinces++;
            }
        }

        return provinces;
    };
};