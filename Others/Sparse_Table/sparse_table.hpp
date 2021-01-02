#include <vector>
using std::vector;

/**
 * 稀疏表 Sparse Table
 * 主要用来解决RMQ(Range Minimum/Maximum Query)问题
 *
 * 其主要思路是根据原数组array构造新的ST矩阵
 * 其中ST[i][j]的含义是以i为开始，长度为2^j的区间的最大值/最小值。(这里使用最大值举例)
 * 可以将区间分成两段长为2^(j-1)
 * 得到如下表达式 ST[i][j] = max{ST[i][j-1], ST[i + 2^(j-1)][j-1]}
 * 其本质就是动态规划。
 *
 * 如果想要求[left, right]区间的最大值 先算 k = ln(len) 向下取整
 * 保证 len <= 2^(k+1) = 2^k + 2^k
 * 可以在[left, left + 2^k]和[right - 2^k + 1, right]这两个区间求最值
 * 当然大多数情况这两个区间都是有重复的部分，但是这并不影响结果。
 * 通过ST表的性质，我们就可以得到最大值就是
 * max{ST[left][k], ST[right - 2^k + 1][k]}
 */
class sparse_table {
   public:
    sparse_table(vector<int> array) {
        int size = array.size();
        ST = vector<vector<int>>(size, vector<int>(size));
        for (int i = 0; i < size; i++) {
            ST[i][0] = array[i];
        }
        for (int j = 1; (1 << j) <= size; j++) {
            for (int i = 0; i + (1 << j) <= size; i++) {
                ST[i][j] =
                    std::max(ST[i][j - 1], ST[i + (1 << (j - 1))][j - 1]);
            }
        }
    }

    int RMQ(int left, int right) {
        int len = right - left + 1;
        int k = ln(len);
        return std::max(ST[left][k], ST[right - (1 << k) + 1][k]);
    }

   private:
    vector<vector<int>> ST;
    // 取对数，利用了浮点数的性质
    // 浮点数在内存中的存储方式为
    // 1bit(符号) 8bit(指数) 23bit(尾数)
    int ln(int x) {
        float fx;
        unsigned long ix, exp;

        fx = (float)x;
        ix = *(unsigned long*)&fx;
        // 将尾数移出，取低八位指数
        exp = (ix >> 23) & 0xff;

        // 减去偏移量
        return exp - 127;
    }
};