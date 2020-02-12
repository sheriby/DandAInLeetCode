#include <iostream>
#include <set>
using std::multiset;

static const auto __ = [] {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();

class MedianFinder {
    // use multiset and two pointer or single pointer
  private:
    multiset<int> s;
    multiset<int>::iterator low, high;

  public:
    /** initialize your data structure here. */
    MedianFinder() = default;

    void addNum(int num) {
        int n = s.size();
        s.insert(num);

        if (!n) {
            low = high = s.begin();
        } else if (n & 1) { // n is odd
            if (num < *low) {
                low--;
            } else {
                high++;
            }
        } else { // n is even
            if (num > *low && num < *high) {
                low++;
                high--;
            } else if (num >= *high) {
                low++;
            } else {
                low = --high;
                // low = -- high => important!
                // if num == *low
                // low num high => low and high is not adjacent!
            }
        }
    }

    double findMedian() {
        std::cout << *low << ", " << *high << std::endl;
        std::cout << "next =>" << *(std::next(low)) << "," << *(std::next(high)) << std::endl;
        return (*low + *high) * 0.5;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */