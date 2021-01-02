#include <queue>
#include <vector>

using std::priority_queue;
using std::vector;

class Solution {
   public:
    // 使用优先级队列，时间复杂度较高
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<std::pair<int, int>> q;
        vector<int> result;

        for (int i = 0; i < k; i++) {
            q.emplace(nums[i], i);
        }

        result.push_back(q.top().first);

        for (int i = k; i < nums.size(); i++) {
            while (!q.empty() && q.top().second <= i - k) {
                q.pop();
            }
            q.emplace(nums[i], i);
            result.push_back(q.top().first);
        }

        return result;
    }
};