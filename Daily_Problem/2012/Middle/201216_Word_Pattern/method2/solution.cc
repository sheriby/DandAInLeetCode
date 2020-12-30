#include <sstream>
#include <string>
#include <unordered_map>

using std::string;
using std::stringstream;
using std::unordered_map;

class Solution {
   public:
    // 可以使用stringstream来实现split类似的效果
    bool wordPattern(string pattern, string str) {
        unordered_map<char, string> map;
        unordered_map<string, char> rmap;
        stringstream ss(str);
        string s;
        for (char c : pattern) {
            if (!(ss >> s) || (map.count(c) == 1 && map[c] != s) ||
                (rmap.count(s) == 1 && rmap[s] != c))
                return false;
            map[c] = s;
            rmap[s] = c;
        }
        return (ss >> s) ? false : true;
    }
};