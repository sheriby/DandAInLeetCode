#include <vector>
using std::vector;

class Solution {
   public:
    // 一种更加简单的方式，查看拐点的数量即可
    int wiggleMaxLength(vector<int>& nums) {
        if (nums.size() <= 1) return nums.size();

        int length = 1;
        int curState = 0;
        int prevState = 0;

        for (size_t i = 0; i < nums.size() - 1; i++) {
            if (nums[i] == nums[i + 1]) continue;

            curState = nums[i + 1] > nums[i] ? 1 : -1;

            if (curState != prevState) {
                length++;
                prevState = curState;
            }
        }

        return length;
    }
};