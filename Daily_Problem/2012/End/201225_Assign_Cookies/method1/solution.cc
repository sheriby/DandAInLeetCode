#include <algorithm>
#include <functional>
#include <vector>

using std::vector;

class Solution {
   public:
    // 典型的贪心算法，按照孩子胃口从小到大，饼干从小到大进行满足
    int findContentChildren(vector<int>& g, vector<int>& s) {
        std::sort(g.begin(), g.end());
        std::sort(s.begin(), s.end());

        int result = 0;
        for (int val : s) {
            if (val >= g[result]) {
                result++;
                if (result == g.size()) break;
            }
        }

        return result;
    }
};