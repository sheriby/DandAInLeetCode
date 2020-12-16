#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using std::string;
using std::unordered_map;
using std::unordered_set;
using std::vector;

class Solution {
   public:
    // C++当中没有split函数，说实话蛮头疼的
    bool wordPattern(string pattern, string s) {
        vector<string> words = split(s, ' ');
        if (pattern.size() != words.size()) return false;

        unordered_map<char, string> map;
        unordered_set<string> set;
        for (size_t i = 0; i < pattern.size(); i++) {
            if (map.count(pattern[i])) {
                if (map[pattern[i]] != words[i]) {
                    return false;
                }
            } else {
                if (set.count(words[i])) {
                    return false;
                } else {
                    map[pattern[i]] = words[i];
                    set.insert(words[i]);
                }
            }
        }

        return true;
    }

   private:
    // 自己实现split函数
    vector<string> split(string str, char sep) {
        vector<string> result;
        int start = -1;
        for (size_t i = 0; i < str.size(); i++) {
            if (str[i] != sep && start == -1) {
                start = i;
                continue;
            }
            if (str[i] == sep && start != -1) {
                result.push_back(str.substr(start, i - start));
                start = -1;
            }
        }
        if (start != -1) {
            result.push_back(str.substr(start));
        }

        return result;
    }
};