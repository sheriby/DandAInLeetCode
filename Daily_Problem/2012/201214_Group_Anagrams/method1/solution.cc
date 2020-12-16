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
        for (int i = 0; i < 26; ++i) {
            s[i + 'a'] = ss[i];
        }
        unordered_map<long long, vector<string>> sets;
        for (auto str : strs) {
            long long ans = calc(str);
            sets[ans].push_back(str);
        }
        vector<vector<string>> ans;
        for (auto it : sets) {
            ans.push_back(it.second);
        }
        return ans;
    }

   private:
    // 使用质数相乘，作为哈希表的键，但是可能会发生冲突的情况。
    const long long mod = 1e9 + 7;
    unordered_map<char, int> s;
    int ss[26] = {2,  3,  5,  7,  11, 13, 17, 19, 23, 29, 31, 37, 41,
                  43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101};
    long long calc(string str) {
        long long ans = 1;
        for (auto c : str) {
            ans *= 1LL * s[c];
            ans %= mod;
        }
        return ans;
    }
};