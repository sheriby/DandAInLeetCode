#include <algorithm>
#include <vector>
using std::vector;

class Solution {
   public:
    // 使用贪心算法，将序列以右端点从小到大排序，第一个则是首区间
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.empty()) return 0;

        std::sort(intervals.begin(), intervals.end(),
                  [](const auto& x, const auto& y) { return x[1] < y[1]; });

        int right = intervals[0][1];
        int result = 1;

        for (auto&& interval : intervals) {
            if (interval[0] >= right) {
                result++;
                right = interval[1];
            }
        }

        return intervals.size() - result;
    }
};