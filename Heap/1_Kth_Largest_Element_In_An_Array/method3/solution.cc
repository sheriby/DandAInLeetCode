#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using std::vector;

class Solution {
  public:
    int findKthLargest(vector<int> &nums, int k) {
        // quick select algorithm which is similiar to quick sort algorithm
        return findKthLargestHelper(nums, 0, nums.size(), k);
    }

  private:
    int findKthLargestHelper(vector<int> &nums, int left, int right, int k) {
        int res = partion(nums, left, right);
        // kth largest is the n-k+1 th smallest.
        if (res == nums.size() - k + 1) {
            return nums[res - 1];
        } else if (res < nums.size() - k + 1) {
            return findKthLargestHelper(nums, res, right, k);
        } else {
            return findKthLargestHelper(nums, left, res, k);
        }
    }

    int partion(vector<int> &nums, int left, int right) { // [left, right)
        if (left == right - 1) {
            return left + 1;
        }
        int baseVal = nums[left];
        std::cout << baseVal << std::endl;
        int p = left;
        int q = left + 1;
        while (q < right) {
            if (nums[q] < baseVal) {
                p++;
                swap(&nums[p], &nums[q]);
            }
            q++;
        }
        swap(&nums[left], &nums[p]);
        // p is the index of the base value
        return p + 1; // it is (p+1)th samller element
    }

    void swap(int *p, int *q) {
        if (p == q) {
            return;
        }
        *p ^= *q ^= *p ^= *q;
    }
};
