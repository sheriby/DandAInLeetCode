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
        if (!head) {
            return nullptr;
        }
        Node *oldNode = head;
        Node *newNode = new Node(oldNode->val);
        nodemap[oldNode] = newNode;

        while (oldNode) {
            newNode->random = getCloneNode(oldNode->random);
            newNode->next = getCloneNode(oldNode->next);

            oldNode = oldNode->next;
            newNode = newNode->next;
        }

        return nodemap[head];
    }

  private:
    std::map<Node *, Node *> nodemap;
    Node *getCloneNode(Node *head) {
        if (head) {
            if (nodemap.find(head) != nodemap.end()) {
                return nodemap[head];
            }
            Node *node = new Node(head->val);
            nodemap[head] = node;
            return node;
        }
        return nullptr;
    }
};