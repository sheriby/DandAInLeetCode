#include <string>
using std::string;

class Solution {
   public:
    // 使用一个map来储存字符之间的映射就可以了
    // 这里因为键和值都是char，而且范围也是确定的，可以使用数组替代map
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size()) return false;

        char maps[128]{0};
        char mapt[128]{0};
        for (size_t i = 0; i < s.size(); i++) {
            int si = s[i];
            int ti = t[i];
            if (maps[si] && maps[si] != t[i]) {
                return false;
            }
            if (!maps[si] && mapt[ti]) return false;
            maps[si] = t[i];
            mapt[ti] = 1;
        }

        return true;
    }
};