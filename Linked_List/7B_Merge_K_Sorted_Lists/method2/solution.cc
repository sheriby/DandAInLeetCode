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
        // divide and conquer algorithm
        // merge sort is a good example of divide and conquer algorithm
        if (lists.size() == 0) {
            return nullptr;
        }
        return mergeKListsHelper(lists, 0, lists.size() - 1);
    }

    ListNode *mergeKListsHelper(vector<ListNode *> &lists, int left,
                                int right) {
        if (left < right) {
            int mid = left + (right - left) / 2;
            ListNode *leftList = mergeKListsHelper(lists, left, mid);
            ListNode *rightList = mergeKListsHelper(lists, mid + 1, right);

            return mergeTwoLists(leftList, rightList);
        } else {
            // std::cout << left << std::endl;
            return lists.at(left);
        }
    }

  private:
    // we have already writeen merge two sorted lists before.
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        // the second methods is two pointer.
        ListNode *p = l1, *q = l2;
        ListNode *head = new ListNode(0);
        ListNode *pos = head;
        while (p && q) {
            if (p->val < q->val) {
                pos->next = p;
                p = p->next;
            } else {
                pos->next = q;
                q = q->next;
            }
            pos = pos->next;
        }

        if (p) {
            pos->next = p;
        } else {
            pos->next = q;
        }

        return head->next;
    }
};