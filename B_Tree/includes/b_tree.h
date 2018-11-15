#include "node.h"
#include <iostream>

class BTree {

 public:
  BTree() {
    root = NULL;
    B_Tree_Create();
  }

   void B_Tree_Insert(int key) {
    Node* r = root;
    if (root->n == 2*t - 1) {
      Node* s = new Node();
      root = s;
      s->leaf = false;
      s->n = 0;
      s->children[0] = r;
      B_Tree_Split_Child(s, 0);
      B_Tree_Insert_NonFull(s, key);
    } else {
      B_Tree_Insert_NonFull(r, key);
    }
  }

 private:
  void B_Tree_Create() {
    Node* x = new Node();
    x->leaf = true;
    root = x;
  }

  void B_Tree_Insert_NonFull(Node* x, int key) {
    
  }

  void B_Tree_Split_Child(Node* x, int loc) {
    Node* z = new Node();
    Node* y = x->children[loc];
    z->leaf = y->leaf;
    z->n = t-1; // in the assignment's case, 1
    for (int i = 0; i < t-1; i++) {
      z->keys[i] = y->keys[i+t]; 
      y->keys[i+t] = -1;          // clear out the slot
    }
    if (!y->leaf) {
      for (int i = 0; i < t; i++) {
        z->children[i] = y->children[i+t];
        y->children[i+t] = NULL;  // clear out the slot
      }
    }
    y->n = t-1;
    for (int i = x->n+1; i > loc+1; i--) {
      x->children[i] = x->children[i-1];
    }
    x->children[loc+1] = z;
    for (int i = x->n; i > loc; i--) {
      x->keys[i+1] = x->keys[i];
    }
    x->keys[loc] = y->keys[t];
    x->n = x->n+1;
  }

  Node* root;
};