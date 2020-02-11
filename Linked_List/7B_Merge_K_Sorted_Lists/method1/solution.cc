#include <algorithm>
#include <iostream>
#include <vector>
using std::vector;

/**
 * The definition from single-linked list
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int val)
        : val(val), next(nullptr) {} // here use nullptr instead of NULL
};

class Solution {
  public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        // the easiest method to solve this problem
        // push all node into a vector and sort it
        // finally, convert this sorted vector to a list
        std::vector<ListNode *> allnode;
        for (ListNode *list : lists) {
            while (list) {
                allnode.push_back(list);
                list = list->next;
            }
        }
        std::sort(allnode.begin(), allnode.end(),
                  [](ListNode *a, ListNode *b) { return a->val < b->val; });
        ListNode *newList = new ListNode(0);
        ListNode *pos = newList;
        for (ListNode *node : allnode) {
            pos->next = node;
            pos = node;
        }
        pos->next = nullptr;
        return newList->next;
    }
};