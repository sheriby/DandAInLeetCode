#include <algorithm>
#include <vector>

using std::vector;

class Solution {
   public:
    // 分解成为两个规则然后做两次遍历
    int candy(vector<int>& ratings) {
        int size = ratings.size();
        vector<int> left(size);

        // 右面大的人分的更多
        for (size_t i = 0; i < size; i++) {
            if (i > 0 && ratings[i] > ratings[i - 1]) {
                left[i] = left[i - 1] + 1;
            } else {
                left[i] = 1;
            }
        }

        // 左面大的人分的更多
        int right = 0, result = 0;
        for (size_t i = size - 1; i + 1 > 0; i--) {
            if (i < size - 1 && ratings[i] > ratings[i + 1]) {
                right++;
            } else {
                right = 1;
            }

            // 两项规则都要满足才行
            result += std::max(left[i], right);
        }

        return result;
    }
};