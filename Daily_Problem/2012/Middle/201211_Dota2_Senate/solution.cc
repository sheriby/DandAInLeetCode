#include <queue>
#include <string>

using std::queue;
using std::string;

class Solution {
   public:
    // 维护两个阵营的队列，很nice的想法
    string predictPartyVictory(string senate) {
        int size = senate.size();
        queue<int> radiant, dire;
        for (int i = 0; i < size; ++i) {
            if (senate[i] == 'R') {
                radiant.push(i);
            } else {
                dire.push(i);
            }
        }
        while (!radiant.empty() && !dire.empty()) {
            if (radiant.front() < dire.front()) {
                radiant.push(radiant.front() + size);
            } else {
                dire.push(dire.front() + size);
            }
            radiant.pop();
            dire.pop();
        }
        return !radiant.empty() ? "Radiant" : "Dire";
    }
};