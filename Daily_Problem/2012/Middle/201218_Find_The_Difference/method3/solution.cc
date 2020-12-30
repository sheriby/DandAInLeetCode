#include <algorithm>
#include <string>

using std::string;

class Solution {
   public:
    // 第三种方式异或运算
    // A^A = 0
    // 0^A = A
    // A^B^A = A^A^B = 0^B = B
    char findTheDifference(string s, string t) {
        char res = 0;
        for (size_t i = 0; i < s.size(); i++) {
            res ^= s[i] ^= t[i];
        }
        return t[s.size()] ^ res;
    }
};