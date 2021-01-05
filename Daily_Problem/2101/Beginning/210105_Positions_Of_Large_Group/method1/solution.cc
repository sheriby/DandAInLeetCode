#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution {
   public:
    vector<vector<int>> largeGroupPositions(string s) {
        vector<vector<int>> result;
        int start = -1;
        int end = -1;
        int count = 0;
        for (int i = 0; i < s.size(); i++) {
            if (!i) {
                start = 0;
                end = 0;
                count++;
            } else if (s[i] == s[i - 1]) {
                if (!count) {
                    start = i;
                    end = i;
                }
                count++;
                end++;
            } else {
                if (end - start > 1) {
                    result.push_back({start, end});
                }
                start = i;
                end = i;
            }
        }
        if (end - start > 1) {
            result.push_back({start, end});
        }

        return result;
    }
};