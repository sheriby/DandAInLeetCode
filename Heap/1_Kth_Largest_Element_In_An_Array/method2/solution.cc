#include <algorithm>
#include <queue>
#include <vector>
using std::vector;

class Solution {
  public:
    int findKthLargest(vector<int> &nums, int k) {
        // ues binary heap to solve this question
        // priority_queue<element type, container, comparator>
        std::priority_queue<int, std::vector<int>, std::greater<int>> q;
        for (int num : nums) {
            if (q.size() < k) {
                q.push(num);
            } else if (num > q.top()) {
                q.pop();
                q.push(num);
            }
        }
        return q.top();
    }
};
