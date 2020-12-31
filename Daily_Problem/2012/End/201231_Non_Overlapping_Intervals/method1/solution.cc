#include <algorithm>
#include <vector>
using std::vector;

class Solution {
   public:
    // 使用动态规划的方法
    // 将intervals按照开始的端点从小到大排序
    // f(i)表示第i个为结束的连续区间数目
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.empty()) return 0;

        std::sort(intervals.begin(), intervals.end(),
                  [](const auto& x, const auto& y) { return x[0] < y[0]; });

        int size = intervals.size();
        vector<int> f(size, 1);

        for (int i = 1; i < size; i++) {
            for (int j = 0; j < i; j++) {
                if (intervals[j][1] <= intervals[i][0]) {
                    f[i] = std::max(f[i], f[j] + 1);
                }
            }
        }

        return size - *std::max_element(f.begin(), f.end());
    }
};