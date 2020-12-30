#include <string>
using std::string;

class Solution {
   public:
    // 也可以将其转换成字符串来处理
    // 但这也并不是一个非常好的方法，字符串和数字之间的转换其实也蛮费事的
    // 只是这种转换函数在标准库中存在罢了
    int monotoneIncreasingDigits(int N) {
        string strN = std::to_string(N);
        int i = 1;
        while (i < strN.length() && strN[i - 1] <= strN[i]) {
            i += 1;
        }
        if (i < strN.length()) {
            while (i > 0 && strN[i - 1] > strN[i]) {
                strN[i - 1] -= 1;
                i -= 1;
            }
            for (i += 1; i < strN.length(); ++i) {
                strN[i] = '9';
            }
        }
        return stoi(strN);
    }
};