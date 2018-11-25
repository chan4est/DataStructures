#ifndef NODE_H_
#define NODE_H_

#include <utility>
#include <algorithm>
#include <iostream>

class Node {
 public:
  Node(int t, bool leaf) {
    this->t = t;
    this->leaf = leaf;
    keys = new int[2*t-1];
    C = new Node *[2*t];
    n = 0;
  }

  void traverse() {
    int i;
    for (i = 0; i < n; i++) {
      if (!leaf) 
        C[i]->traverse();
      std::cout << " " << keys[i];
    }
    if (!leaf)
      C[i]->traverse();
  }

  void insertNonFull(int key) {
    int i = n-1;
    if (leaf) {
      while (i >= 0 && keys[i] > key) {
        keys[i+1] =  keys[i];
        i--;
      }
      keys[i+1] = key;
      n++;
    } else {
      while (i >= 0 && keys[i] > key) {
        i--;
      } 
      if (C[i+1]->n == 2*t - 1) {
        splitChild(i+1, C[i+1]);
        if (keys[i+1] < key)
          i++;
      }
      C[i+1]->insertNonFull(key);
    }
  }

  void splitChild(int i, Node* y) {
    Node* z = new Node(y->t, y->leaf);
    z->n = t-1;

    for (int j = 0; j < t-1; j++) {
      z->keys[j] = y->keys[j+t];
    }
    if (!y->leaf) {
      for (int j = 0; j < t; j++) {
        z->C[j] = y->C[j+t];
      }
    }
    y->n = t-1;
    for (int j = n; j >= i+1; j--) {
      C[j+1] = C[j];
    }
    C[i+1] = z;
    for (int j = n-1; j >= i; j--) {
      keys[j+1] = keys[j];
    }
    keys[i] = y->keys[t-1];
    n++;
  }

  int t;
  int* keys;
  Node** C;
  int n;
  bool leaf;
};

#endif // NODE_H_