#include <unordered_set>
#include <vector>

using std::unordered_set;
using std::vector;

class Solution {
   public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> s;
        for (int x : nums) {
            if (s.find(x) != s.end()) {
                return true;
            }
            s.insert(x);
        }
        return false;
    }
};