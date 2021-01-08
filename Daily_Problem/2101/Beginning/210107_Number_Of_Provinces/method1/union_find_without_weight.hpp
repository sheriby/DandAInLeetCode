#include <vector>
using std::vector;

class UnionFind {
   public:
    UnionFind(int n) {
        parent.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
        this->number = n;
    }

    int find(int x) {
        if (x != parent[x]) {
            parent[x] = find(parent[x]);
        }

        return parent[x];
    }

    void union_(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX == rootY) return;
        parent[rootX] = rootY;
        this->number--;
    }

    bool isConnected(int x, int y) { return find(x) == find(y); }

    int numberOfSet() { return this->number; }

   private:
    vector<int> parent;
    int number;
};