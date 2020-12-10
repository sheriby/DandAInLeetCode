#include <algorithm>
#include <iostream>
#include <vector>
using std::vector;

class Solution {
   public:
    // 纸币的价格只有三种，所以简单分类讨论一下即可。
    bool lemonadeChange(vector<int>& bills) {
        int five = 0, ten = 0;
        for (auto& bill : bills) {
            if (bill == 5) {
                five++;
            } else if (bill == 10) {
                if (!five) return false;
                five--;
                ten++;
            } else if (bill == 20) {
                if (five && ten) {
                    five--;
                    ten--;
                } else if (five >= 3) {
                    five -= 3;
                } else
                    return false;
            }
        }

        return true;
    }
};