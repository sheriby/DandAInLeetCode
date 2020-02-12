#include <vector>
#include <algorithm>
using std::vector;

class Solution {
  public:
    int findKthLargest(vector<int> &nums, int k) {
        // The easiest method is to sort this vector
        std::sort(nums.begin(), nums.end(), [](int x, int y) { return x > y; });

        return nums.at(k - 1);
    }
};

