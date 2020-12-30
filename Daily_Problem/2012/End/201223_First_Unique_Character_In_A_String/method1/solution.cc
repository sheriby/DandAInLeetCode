#include <string>

using std::string;

class Solution {
   public:
    int firstUniqChar(string s) {
        if (!s.size()) return -1;
        int num[26]{0};
        // 字符串中各个字母出现的次数，用于判断是否重复
        for (char ch : s) {
            num[ch - 'a']++;
        }

        // 从前到后找到第一个不是重复的
        for (size_t i = 0; i < s.size(); i++) {
            if (num[s[i] - 'a'] == 1) {
                return i;
            }
        }

        return -1;
    }
};