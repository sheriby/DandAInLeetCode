#include <algorithm>
#include <vector>

using std::vector;

class Solution {
   public:
    // 维护两个序列的长度，递增序列和递减序列
    // 当递减序列的长度等于递增序列的时候，将递增序列的尾作为递减序列的头
    int candy(vector<int>& ratings) {
        int size = ratings.size();
        int result = 1;
        int inc = 1, dec = 0, pre = 1;
        for (size_t i = 1; i < size; i++) {
            if (ratings[i] >= ratings[i - 1]) {
                dec = 0;
                pre = ratings[i] == ratings[i - 1] ? 1 : pre + 1;
                result += pre;
                inc = pre;
            } else {
                dec++;
                if (dec == inc) {
                    dec++;
                }
                result += dec;
                pre = 1;
            }
        }

        return result;
    }
};