#include <iostream>
#include <map>

/**
 * Definition for a node
 */
class Node {
  public:
    int val;
    Node *next;
    Node *random;

    Node(int _val) {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};

class Solution {
  public:
    Node *copyRandomList(Node *head) {
        // an unbelievable method without using map
        if (!head) {
            return nullptr;
        }
        Node *oldNode = head;
        Node *newNode = nullptr;

        // oldList: A => B => C
        // newList: A => A' => B => B' => C => C'
        while (oldNode) {
            newNode = new Node(oldNode->val);
            newNode->next = oldNode->next;
            oldNode->next = newNode;
            oldNode = newNode->next;
        }

        // handle the random pointer
        Node *pos = head;
        while (pos) {
            // nullptr judge! important!
            pos->next->random = pos->random ? pos->random->next : nullptr; 
            pos = pos->next->next;
        }

        Node *oldList = head;
        Node *newList = head->next;
        Node *newHead = newList;
        while (oldList) {
            oldList->next = oldList->next->next;
            // nullptr judge! important!
            newList->next = newList->next?newList->next->next:nullptr; 

            oldList = oldList->next;
            newList = newList->next;
        }

        return newHead;
    }
};