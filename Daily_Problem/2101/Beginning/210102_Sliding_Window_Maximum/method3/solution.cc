#include <vector>

using std::vector;

class Solution {
   public:
    // 使用分组的方法
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int size = nums.size();
        vector<int> prefix(size), sufffix(size);

        // 以i结束的前缀
        for (int i = 0; i < size; i++) {
            if (i % k == 0) {
                prefix[i] = nums[i];
            } else {
                prefix[i] = std::max(prefix[i - 1], nums[i]);
            }
        }

        // 以i开始的后缀
        for (int i = size - 1; i >= 0; i--) {
            if (i == size - 1 || i % k == 0) {
                sufffix[i] = nums[i];
            } else {
                sufffix[i] = std::max(sufffix[i + 1], nums[i]);
            }
        }

        vector<int> result;
        for (int i = 0; i < size - k + 1; i++) {
            result.push_back(std::max(sufffix[i], prefix[i + k - 1]));
        }

        return result;
    }
};