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
        std::vector<int> s; // use vector as stack.
        std::string result = "";
        for (int i = 0; i < num.length(); ++i) {
            int number = num[i] - '0';
            while (s.size() && number < s.back() && k > 0) {
                s.pop_back();
                k--;
            }
            if (number || s.size()) {
                s.push_back(number);
            }
        }

        while (s.size() && k > 0) {
            s.pop_back();
            k--;
        }

        for (int i = 0; i < s.size(); ++i) {
            // result += s[i];
            result.append(1, '0' + s[i]);
        }

        if (result == "") {
            return "0";
        }
        return result;
    }
};
