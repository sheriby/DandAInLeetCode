#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution {
   public:
    // 使用回溯解决此问题
    vector<int> splitIntoFibonacci(string S) {
        vector<int> result;
        backTrack(result, S, 0, 0, 0);
        return result;
    }

   private:
    bool backTrack(vector<int>& result, string str, int index, int prev,
                   long long sum) {
        // 此时已经完全遍历完字符串
        if (index == str.size()) {
            // 列表当中至少要有三个元素
            return result.size() >= 3;
        }

        long long cur = 0;
        for (size_t i = index; i < str.size(); i++) {
            // 数字不能以0开头
            if (i > index && str[index] == '0') break;

            cur = 10 * cur + str[i] - '0';
            // 数字超过了上限
            if (cur > INT32_MAX) break;

            // 列表当中已经有了两个元素
            if (result.size() >= 2) {
                // 现在的值还没有前两个元素的总和大
                if (cur < sum) continue;
                // 超过了前两个数的总和
                else if (cur > sum)
                    break;
            }

            // 此时刚好等于前两个数的总和
            result.push_back(cur);
            // 回溯寻找下一个数
            if (backTrack(result, str, i + 1, cur, cur + prev)) {
                return true;
            }
            // 寻找失败将之前的元素去除
            result.pop_back();
        }

        return false;
    }
};