#include <iostream>
#include <string>
#include <vector>
using std::string;

static const auto __ = [] {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();

class Solution {
  public:
    string removeKdigits(string num, int k) {
        if (num.length() == k) {
            return string(1, '0');
        }
        string stk;
        int i = 0;
        while (k > 0 && i < num.size()) {
            if (stk.empty() || stk.back() <= num[i]) {
                stk.push_back(num[i]);
                ++i;
            } else {
                stk.pop_back();
                --k;
            }
        }

        stk = stk.substr(0, stk.size() - k) + num.substr(i);

        size_t beginIndex = 0;
        while (beginIndex < stk.size() - 1 && stk[beginIndex] == '0') {
            ++beginIndex;
        }
        return stk.substr(beginIndex);
    }
};
