#ifndef RED_BLACK_TREE_H_
#define RED_BLACK_TREE_H_

#include "node.h"
#include <iostream>
#include <string>

const std::string COLOR[2] = {"red", "black"};

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
          node->parent = temp;
          break;
        }
      } else {
          // going left
        if (temp->left) {
          temp = temp->left;
        } else {
          temp->left = node;
          temp->left->parent = temp;
          break;
        }
      }
    }
  }


  void insert(int key) {
    Node* node = new Node(key, red);
    // case 0. Z is the root
    if (!root) { 
      node->recolor();
      this->root = node;
      return;
    } 
    insert_node(node);
    this->print();
    while (node != this->root && node->color != black &&
           node->parent->color == red) 
    {
      // Uncle is Red
      std::cout << node->parent->parent->color;
      if (auto uncle = node->red_uncle_check()) {
        if (uncle != NULL) {
          node->parent->recolor();
          node->parent->parent->recolor();
          uncle->recolor();
          node = uncle->parent;
        }
      }
      // Uncle is Black
      else if (int uncle_case = node->black_uncle_check() != -1) {
        // std::cout << uncle_case << std::endl;
        switch (uncle_case) {
          // Uncle Black and Left Left Case
          // 1.) Right rotate grandparent
          // 2.) Swap colors of grandparent and parent
          case 1 : {
            auto grand = node->parent->parent;
            node->parent->recolor();
            grand->recolor();
            right_rotation(grand);
            break;
          }
          // Uncle Black and Left Right Case
          // Left Rotate p
          // Apply Left Lefy Case
          case 2 : {
            auto grand = node->parent->parent;
            node->recolor();
            grand->recolor();
            left_rotation(node->parent);
            right_rotation(grand);
            break;
          }
          // Uncle Black and Right Right Case
          // 1.) Left Rotate grandparent
          // 2.) Swap colors of g and p
          case 3 : {
            std::cout << "here" << std::endl;
            auto grand = node->parent->parent;
            node->parent->recolor();
            grand->recolor();
            left_rotation(grand);
            break;
          }
          // Uncle Black and Right Left Case
          // 1.) Right Rotate parent
          // 2.) Apply Right Right Case
          case 4 : {
            auto grand = node->parent->parent;
            node->recolor();
            grand->recolor();
            right_rotation(node->parent);
            left_rotation(grand);
            break;
          }
          default : break;
        }
      } 
      this->root->color = black;
    }
  }
  
  // <- <- <- <- <-
  void left_rotation(Node* x) {
    std::cout << "single rotate left" << std::endl;
    Node* y = x->right;     // right child of target
    x->right = y->left;     // changing target's right child to be y's left
    if (y->left) {
      y->left->parent = x;  // setting parent, if not NULL
    }
    y->parent = x->parent; // setting parent of new 'root'
    if (!x->parent) {
      this->root = y;
      this->root->parent = NULL;
    } else if (x == x->parent->left) {
      x->parent->left = y;   // if target was a left child
    } else {
      x->parent->right = y;   // if target was a right child
    }
    y->left = x;    // new 'root' changes left to be it's old parent
    x->parent = y;  // and now, the parent pointer is set up properly
  }

  // Same thing, just in reverse. New var names for practice sake.
  void right_rotation(Node* x) {
    Node* y = x->left;     // right child of target
    x->left = y->right;     // changing target's right child to be y's left
    if (y->right) {
      y->right->parent = x;  // setting parent, if not NULL
    }
    y->parent = x->parent; // setting parent of new 'root'
    if (!x->parent) {
      this->root = y;
      this->root->parent = NULL;
    } else if (x == x->parent->right) {
      x->parent->right = y;   // if target was a left child
    } else {
      x->parent->left = y;   // if target was a right child
    }
    y->right = x;    // new 'root' changes left to be it's old parent
    x->parent = y;  // and now, the parent pointer is set up properly
  }

  void print() {
    this->rec_print("", this->root, false);
  }

  // https://stackoverflow.com/questions/36802354/print-binary-tree-in-a-pretty-way-using-c
  void rec_print(const std::string& prefix, const Node* node, bool isLeft) {
    if (node) {
        std::cout << prefix;
        std::cout << (isLeft ? "├──" : "└──" );
        // print the value of the node
        std::cout << node->key << " : " << COLOR[node->color] << std::endl;
        // enter the next tree level - left and right branch
        rec_print(prefix + (isLeft ? "│   " : "    "), node->left, true);
        rec_print(prefix + (isLeft ? "│   " : "    "), node->right, false);
    }
  }
  Node* root;
};


#endif // RED_BLACK_TREE_H_