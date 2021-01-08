#include <vector>
using std::vector;

class Solution {
   public:
    // 环状替代 使用O(1)的空间
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        int count = gcd(n, k);
        for (int i = 0; i < count; i++) {
            int cur = i;
            int prev = nums[cur];
            do {
                int next = (cur + k) % n;
                std::swap(prev, nums[next]);
                cur = next;
            } while (cur != i);
        }
    }

   private:
    int gcd(int x, int y) { return y ? gcd(y, x % y) : x; }
};