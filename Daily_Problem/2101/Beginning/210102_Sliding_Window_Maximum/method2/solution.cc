#include <deque>
#include <vector>

using std::deque;
using std::vector;

class Solution {
   public:
    // 使用单调队列
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if (k == 1) return nums;
        vector<int> result;
        deque<int> q;

        for (int i = 0; i < k; i++) {
            while (!q.empty() && nums[i] >= nums[q.back()]) {
                q.pop_back();
            }
            q.push_back(i);
        }

        result.push_back(nums[q.front()]);

        for (int i = k; i < nums.size(); i++) {
            while (!q.empty() && nums[i] >= nums[q.back()]) {
                q.pop_back();
            }
            q.push_back(i);
            while (q.front() <= i - k) {
                q.pop_front();
            }
            result.push_back(nums[q.front()]);
        }

        return result;
    }
};