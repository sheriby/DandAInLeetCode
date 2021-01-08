#include <vector>
using std::vector;

// 并查集是一种比较常用的数据结构
// 可以方便的进行并、查操作
// 查就是看两个节点之间是否存在某种关联
// 并操作就是使两个节点产生某种关联
// 这里的并查集加入了权值，x指向y就表示 x * weight[x] = y
class UnionFind {
   public:
    UnionFind(int n) {
        parent.resize(n);
        weight.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            weight[i] = 1.0;
        }
    }

    // 找到x的父节点
    // 执行路径压缩算法
    int find(int x) {
        if (x != parent[x]) {
            int p = parent[x];
            parent[x] = find(p);
            weight[x] *= weight[p];
        }

        return parent[x];
    }

    // 合并两个节点
    // x / y = value
    void union_(int x, int y, double value) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX == rootY) return;

        parent[rootX] = rootY;
        weight[rootX] = weight[y] / (weight[x] * value);
    }

    // 如果两个节点有关联，返回x/y,否则返回-1
    double isConnected(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX == rootY)
            return weight[y] / weight[x];
        else
            return -1.0;
    }

   private:
    vector<int> parent;
    vector<double> weight;
};