#include <iostream>
#include <map>
#include <vector>

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
        if (!head) {
            return nullptr;
        }
        // use map to store the random pointer
        std::vector<Node *> nodes;
        std::map<Node *, int> randmap;
        Node *node = new Node(0);
        Node *pos = node;
        int cot = 0;
        while (head) {
            pos->next = new Node(head->val);
            pos = pos->next;
            pos->random = head->random;

            nodes.push_back(pos);
            if (head) {
                randmap[head] = cot;
            }
            cot++;
            head = head->next;
        }
        pos = node->next;
        while (pos) {
            if (pos->random) {
                pos->random = nodes[randmap[pos->random]];
            }
            pos = pos->next;
        }

        return node->next;
    }
};