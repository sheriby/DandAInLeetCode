#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution {
   public:
    string removeDuplicateLetters(string s) {
        // visit表示之前是否遇到过此字符
        // number表示该字符还剩余多少个
        vector<int> visit(26), number(26);
        for (char ch : s) {
            number[ch - 'a']++;
        }

        string result;
        for (char ch : s) {
            if (!visit[ch - 'a']) {
                // 字符串的末尾总是关键字符
                while (!result.empty() && result.back() > ch) {
                    // 如果后面还有该字符的话，就删掉等后面的
                    if (number[result.back() - 'a'] > 0) {
                        visit[result.back() - 'a'] = 0;
                        result.pop_back();
                    } else {
                        break;
                    }
                }
                visit[ch - 'a'] = 1;
                result.push_back(ch);
            }
            number[ch - 'a'] -= 1;
        }
        return result;
    }
};