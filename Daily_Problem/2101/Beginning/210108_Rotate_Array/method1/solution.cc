#include <vector>
using std::vector;

class Solution {
   public:
    // 最简单的方法，使用一个临时数组
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        vector<int> tmp = nums;
        for (int i = 0; i < n; i++) {
            int index = (i - k < 0) ? i + n - k : i - k;
            nums[i] = tmp[index];
        }
    }
};