#include <iostream>
#include <queue>
#include <vector>
using std::priority_queue;
using std::vector;

static const auto __ = []{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();

class MedianFinder {
  private:
    priority_queue<int, vector<int>> big;                      // max heap
    priority_queue<int, vector<int>, std::greater<int>> small; // min heap

  public:
    /** initialize your data structure here. */
    MedianFinder() = default;

    void addNum(int num) {
        if (big.size() == 0) {
            big.push(num);
        } else if (big.size() == small.size()) {
            if (num > small.top()) {
                small.push(num);
            } else {
                big.push(num);
            }
        } else if (big.size() > small.size()) {
            if (num < big.top()) {
                int val = big.top();
                big.pop();
                big.push(num);
                small.push(val);
            } else {
                small.push(num);
            }
        } else {
            if (num > small.top()) {
                int val = small.top();
                small.pop();
                small.push(num);
                big.push(val);
            } else {
                big.push(num);
            }
        }
    }

    double findMedian() {
        if (small.size() == big.size()) {
            return (small.top() + big.top()) * 1.0 / 2;
        } else if (small.size() > big.size()) {
            return small.top();
        } else {
            return big.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */