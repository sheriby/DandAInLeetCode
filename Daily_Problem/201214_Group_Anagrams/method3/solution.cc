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
            string ans = anagramHash(str);
            sets[ans].push_back(str);
        }
        vector<vector<string>> ans;
        for (auto it : sets) {
            ans.push_back(it.second);
        }
        return ans;
    }

   private:
    // 将计数字符串作为键 如aba变成a2b1
    string anagramHash(string str) {
        string result;
        vector<int> arr(26, 0);
        for (auto&& s : str) {
            arr[s - 'a']++;
        }
        for (size_t i = 0; i < arr.size(); i++) {
            if (arr[i]) {
                result += 'a' + i;
                result += std::to_string(arr[i]);
            }
        }
        return result;
    }
};