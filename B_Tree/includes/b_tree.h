#include "node.h"
#include <iostream>
#include <queue>

class BTree {

 public:
  BTree(int t) : root(NULL), t(t) {}

  void insert(int key) {
    if (root == NULL) {
      root = new Node(t, true);
      root->keys[0] = key;
      root->n = 1;
    }
    else {
      if (root->n == 2*t-1) {
        Node* temp = new Node(t, false);
        temp->C[0] = root;
        temp->splitChild(0, root);
        int i = 0;
        if (temp->keys[0] < key)
          i++;
        temp->C[i]->insertNonFull(key);
        root = temp;
      } else {
        root->insertNonFull(key);
      }
    }
  }

  void print() {
    std::queue<Node*> q;
    q.push(root);
    int depth = 0;
    while (!q.empty()) {
      std::queue<Node*> next;
      std::cout << "Depth: " << depth << '\t';
      while (!q.empty()) {
        Node* temp = q.front();
        q.pop();
        std::cout << "[";
        for (int i = 0; i < temp->n-1; i++) {
          std::cout << temp->keys[i] << " ";
        }
        std::cout << temp->keys[temp->n-1] << "]";
        if (!temp->leaf) {
          for (int i = 0; i < temp->n+1; i++) {
            if (temp->C[i]) {
              next.push(temp->C[i]);
            }
          }
        }
      }
      std::cout << std::endl;
      depth++;
      q = next;
    }
  }

  Node* root;
  int t;
};