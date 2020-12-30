#include <algorithm>
#include <string>

using std::string;

class Solution {
   public:
    // 最简单的方法，排序
    char findTheDifference(string s, string t) {
        std::sort(s.begin(), s.end());
        std::sort(t.begin(), t.end());
        for (size_t i = 0; i < s.size(); i++) {
            if (s[i] != t[i]) {
                return t[i];
            }
        }
        return t[s.size()];
    }
};