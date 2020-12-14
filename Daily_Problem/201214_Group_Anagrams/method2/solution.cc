#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>

using std::string;
using std::unordered_map;
using std::vector;

class Solution {
   public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> sets;
        for (auto str : strs) {
            string ans = orderString(str);
            sets[ans].push_back(str);
        }
        vector<vector<string>> ans;
        for (auto it : sets) {
            ans.push_back(it.second);
        }
        return ans;
    }

   private:
    // 将其排序之后作为哈希表的键
    unordered_map<char, int> s;
    string orderString(string s) {
        std::sort(s.begin(), s.end());
        return s;
    }
};