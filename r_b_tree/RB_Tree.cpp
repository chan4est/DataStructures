#include "Node.h"

class RedBlackTree {

 public:
 /**
  * 1.) A node is either RED or BLACK.
  * 2.) The root and leaves (NULL) are BLACK.
  * 3.) If a node is RED, then its children are BLACK
  * 4.) All paths from a node to its NULL descendants
  *     contain the same number of BLACK nodes.
  */ 
  RedBlackTree() {
    this->root = NULL;
  }

  // handles basic insert. top 98% on leetcode!
  void insert_node(Node* node) {
    Node* temp = root;
    while (true) {
      if (temp->key < node->key) {
          // going right 
        if (temp->right) {
          temp = temp->right;
        } else {
          temp->right = node;
          temp->right->parent = temp->right;
          break;
        }
      } else {
          // going left
        if (temp->left) {
          temp = temp->left;
        } else {
          temp->left = node;
          temp->left->parent = temp->left;
          break;
        }
      }
    }
  }





  void insert(int key) {
    Node* node = new Node(key, red);
    if (!root) { 
      node->color = black;
      this->root = node;
      return;
    } 
    insert_node(node);
    // case 1. Z.uncle = red;
    if (auto uncle = node->red_uncle_check()) {
      node->parent->recolor();
      node->parent->parent->recolor();
      uncle->recolor();
    }
    // case 2. Z.uncle = black(triangle)
    else if (node->parent->parent &&  // grandparent exists
      node->parent->parent->right &&  // grandparent has a right child
      node->parent->parent->right == node->parent &&  //that right node is your parent
      node->parent->parent->right->color == black // and its color is black
    )
    else if (node->parent->parent &&
      node->parent->parent->left &&
      node->parent->parent->left == node->parent;
    )
  }

  // <- <- <- <- <-
  void left_rotation(Node* x) {
    Node* y = x->right;     // right child of target
    x->right = y->left;     // changing target's right child to be y's left
    if (y->left) {
      y->left->parent = x;  // setting parent, if not NULL
    }
    y->parent = x->parent; // setting parent of new 'root'
    if (!x->parent) {
      this->root = y;
    } else if (x == x->parent->left) {
      x->parent->left = y;   // if target was a left child
    } else {
      x->parent->left = y;   // if target was a right child
    }
    y->left = x;    // new 'root' changes left to be it's old parent
    x->parent = y;  // and now, the parent pointer is set up properly
  }

  // Same thing, just in reverse. New var names for practice sake.
  void right_rotation(Node* target) {
    Node* new_root = target->left;
    target->left = new_root->right;
    if (!target->parent) {
      this->root = new_root;
    } else if (target == target->parent->left) {
      target->parent->left = new_root;
    } else {
      target->parent->right = new_root;
    }
    new_root->right = target;
    target->parent = new_root;
  }

  Node* root;
};


int main(int argc, char** argv) {
  RedBlackTree* rb_tree = new RedBlackTree();
}
