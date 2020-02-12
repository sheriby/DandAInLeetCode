#include <algorithm>
#include <iostream>
#include <vector>
using std::vector;

static const auto __ = [] {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();

class Solution {
  public:
    int findContentChildren(vector<int> &g, vector<int> &s) {
        // the easiest method
        std::sort(g.begin(), g.end());
        std::sort(s.begin(), s.end());

        int k = 0;
        int cot = 0;
        for (size_t i = 0; i < g.size();) {
            if (k == g.size()) {
                return cot;
            }
            if (g[i] <= s[k]) {
                cot++;
                i++;
            }
            k++;
        }
        return cot;
    }
};