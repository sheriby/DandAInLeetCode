#include <string>
using std::string;

class Solution {
   public:
    // 这里使用map存放上一次出现的位置
    // 对于两个字符来说，要么都是第一次出现，要么上一次出现的位置相同
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size()) return false;

        char maps[128]{0};
        char mapt[128]{0};
        for (size_t i = 0; i < s.size(); i++) {
            if (maps[s[i]] != mapt[t[i]]) return false;
            maps[s[i]] = mapt[t[i]] = i + 1;
        }

        return true;
    }
};