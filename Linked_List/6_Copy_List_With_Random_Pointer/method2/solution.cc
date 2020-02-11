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
        // use backtracking method
        if (!head) {
            return nullptr;
        }

        // this node already exists! (this node has been copied!)
        if (nodemap.find(head) != nodemap.end()) {
            return nodemap[head];
        }

        Node *node = new Node(head->val);
        nodemap[head] = node;

        node->next = copyRandomList(head->next);
        node->random = copyRandomList(head->random);

        return node;
    }

  private:
    // use a map to store the mapping from original list to copy list.
    std::map<Node *, Node *> nodemap;
};