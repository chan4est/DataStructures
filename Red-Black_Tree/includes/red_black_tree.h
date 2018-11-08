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
    while (node != this->root && node->color != black &&
           node->parent->color == red) 
    {
      if (auto uncle = node->red_uncle_check()) {
        if (uncle != NULL) {
          node->parent->recolor();
          node->parent->parent->recolor();
          uncle->recolor();
          node = uncle->parent;
        }
      }
       // case 2. Z.uncle = black(triangle)
      else {
        if (auto uncle = node->black_triangle_check()) {
          // right rotation if you're on the left
          if (node->parent->left == node) {
            right_rotation(node);
          } else {
            left_rotation(node);
          }
        }
         // case 3. Z.uncle = black(line)
        node->parent->recolor();
        node->parent->parent->recolor();
        if (node->parent->parent->right == node->parent) {
          left_rotation(node->parent->parent);
        } else {
          right_rotation(node->parent->parent);
        }
      }
      this->root->color = black;
    }
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
  void right_rotation(Node* target) {
    Node* new_root = target->left;
    target->left = new_root->right;
    if (!target->parent) {
      this->root = new_root;
      this->root->parent = NULL;
    } else if (target == target->parent->left) {
      target->parent->left = new_root;
    } else {
      target->parent->right = new_root;
    }
    new_root->right = target;
    target->parent = new_root;
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