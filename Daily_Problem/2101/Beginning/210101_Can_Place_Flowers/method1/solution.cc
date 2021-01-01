#include <vector>

using std::vector;

class Solution {
   public:
    // 算是一种贪心算法吧, 从前到后，如果可以种植就种
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        bool beforeOne = false;
        int count = 0;
        for (int i = 0; i < flowerbed.size(); i++) {
            if (flowerbed[i]) {
                beforeOne = true;
            } else {
                if (!beforeOne &&
                    (i == flowerbed.size() - 1 || !flowerbed[i + 1])) {
                    count++;
                    beforeOne = true;
                } else {
                    beforeOne = false;
                }
            }
            if (count >= n) return true;
        }

        return false;
    }
};