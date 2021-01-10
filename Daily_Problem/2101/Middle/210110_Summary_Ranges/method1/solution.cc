#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution {
   public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> result;
        if (nums.empty()) return result;

        int n = nums.size();
        int i = 0;
        for (int i = 0; i < n; i++) {
            string str = std::to_string(nums[i]);
            int len = 0;
            for (int j = i + 1; j < n; j++, i++) {
                if (nums[j] == nums[i] + 1)
                    len++;
                else
                    break;
            }
            if (len) str.append("->" + std::to_string(nums[i]));
            result.push_back(str);
        }

        return result;
    }
};