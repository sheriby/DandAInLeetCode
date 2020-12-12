#include <vector>
using std::vector;

class Solution {
   public:
    int wiggleMaxLength(vector<int>& nums) {
        if (nums.size() <= 1) return nums.size();

        const int DOWN = 0;
        const int UP = 1;
        const int BEGIN = 2;
        int STATE = BEGIN;
        int length = 1;

        // 状态转换自动机
        for (size_t i = 0; i < nums.size() - 1; i++) {
            switch (STATE) {
                case BEGIN:
                    if (nums[i] < nums[i + 1]) {
                        STATE = UP;
                        length++;
                    } else if (nums[i] > nums[i + 1]) {
                        STATE = DOWN;
                        length++;
                    }
                    break;
                case DOWN:
                    if (nums[i] < nums[i + 1]) {
                        STATE = UP;
                        length++;
                    }
                    break;
                case UP:
                    if (nums[i] > nums[i + 1]) {
                        STATE = DOWN;
                        length++;
                    }
                    break;
            }
        }

        return length;
    }
};