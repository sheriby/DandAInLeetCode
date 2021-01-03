#include <limits.h>

#include <vector>
using std::vector;

class segment_tree {
   public:
    segment_tree(vector<int>& array) {
        this->array = array;
        int size = array.size();
        segTree = vector<int>(size << 2);
        buildTree(1, 1, size);
    }

    void update(int index, int value) {
        update(index + 1, value, 1, 1, array.size());
    }

    int query(int left, int right) {
        return query(left + 1, right + 1, 1, 1, array.size());
    }

   private:
    vector<int> segTree;
    vector<int> array;
    void buildTree(int k, int l, int r) {
        if (l == r) {
            segTree[k] = array[l - 1];
        } else {
            int m = l + ((r - l) >> 1);
            buildTree(k << 1, l, m);
            buildTree(k << 1 | 1, m + 1, r);
            segTree[k] = std::max(segTree[k << 1], segTree[k << 1 | 1]);
        }
    }

    void update(int index, int value, int k, int l, int r) {
        if (l == r) {
            segTree[k] = value;
            array[index - 1] = value;
        } else {
            int m = l + ((r - l) >> 1);
            if (index <= m)
                update(index, value, k << 1, l, m);
            else
                update(index, value, k << 1 | 1, m + 1, r);
            segTree[k] = std::max(segTree[k << 1], segTree[k << 1 | 1]);
        }
    }

    int query(int left, int right, int k, int l, int r) {
        if (left <= l && r <= right) {
            return segTree[k];
        } else {
            int res = INT_MIN;
            int m = l + ((r - l) >> 1);
            if (left <= m)
                res = std::max(res, query(left, right, k << 1, l, m));

            if (right > m)
                res = std::max(res, query(left, right, k << 1 | 1, m + 1, r));

            return res;
        }
    }
};