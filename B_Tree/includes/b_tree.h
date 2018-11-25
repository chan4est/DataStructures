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

  void traverse() { if (root) { root->traverse(); } }

  void print() {
    std::queue<Node*> q;
    q.push(this->root);
    int depth = 0;

    while (!q.empty()) {
      std::queue<Node*> level;
      std::cout << "depth : " << depth << std::endl;

      while (!q.empty()) {
        Node* temp = q.front();
        q.pop();
        std::cout << "[";
        for (int i = 1; i <= temp->n; i++) {
          std::cout << temp->keys[i] << " ";
        }
        std::cout << "]";
        if (!temp->leaf) {
          for (int i = 0; i < temp->n+1; i++) {
            level.push(temp->C[i]);
          }
        }
      }
      std::cout << std::endl;
      depth++;
      q = level;
    }
  }

  Node* root;
  int t;
};