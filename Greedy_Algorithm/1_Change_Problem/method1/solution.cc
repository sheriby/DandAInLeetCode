#include <iostream>

class Solution {
  private:
    const int vals[7] = {100, 50, 20, 10, 5, 2, 1};

  public:
    int changeNums(int money) {
        // use greedy algorithm
        // we should use money as big as possible unless
        // this money value is bigger than change value;
        int cot = 0;
        for (size_t i = 0; i < 7;) {
            if (!money) {
                break;
            }
            if (money >= vals[i]) {
                money -= vals[i];
                cot++;
            } else {
                i++;
            }
        }
        return cot;
    }
};
