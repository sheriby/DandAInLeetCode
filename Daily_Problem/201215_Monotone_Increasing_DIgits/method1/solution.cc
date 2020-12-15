#include <vector>
using std::vector;

class Solution {
   public:
    // 将数字变成各位的数字数组
    int monotoneIncreasingDigits(int N) {
        vector<int> numbers;
        while (N) {
            numbers.push_back(N % 10);
            N /= 10;
        }

        for (int i = 0; i + 1 < numbers.size(); i++) {
            if (numbers[i] >= numbers[i + 1]) {
                continue;
            } else {
                numbers[i + 1]--;
                for (int j = 0; j <= i; j++) {
                    numbers[j] = 9;
                }
            }
        }

        while (true) {
            if (numbers.back() == 0) {
                numbers.pop_back();
            }
            break;
        }

        int result = 0;
        for (int i = numbers.size() - 1; i >= 0; i--) {
            result *= 10;
            result += numbers[i];
        }

        return result;
    }
};