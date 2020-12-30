#include <algorithm>
#include <string>

using std::string;

class Solution {
   public:
    // 第二种方法，求和
    char findTheDifference(string s, string t) {
        char res = 0;
        for (size_t i = 0; i < s.size(); i++) {
            res += t[i] - s[i];
        }
        return t[s.size()] + res;
    }
};