#ifndef NODE_H_
#define NODE_H_

#include <string>
#include <utility>

enum Color { red, black };

class Node {

 public:
    Node(int key, Color color) {
      this->key = key;
      this->color = color;
      this->left = NULL;
      this->right = NULL;
      this->parent = NULL;
    }

    Node* red_uncle_check() {
      // uncle on the right and red
      if (this->parent->parent && // grandparent exists
          this->parent->parent->right && // grandparent has a right node
          this->parent->parent->right != this->parent &&
          this->parent->parent->right->color == red) // that right node is not your parent (uncle)
      {
        return (this->parent->parent->right);
      } 
      // uncle on the left and red
      else if (this->parent->parent && // grandparent exists
               this->parent->parent->left && // grandparent has a left node
               this->parent->parent->left != this->parent && // that left node is not your parent (uncle)
               this->parent->parent->left->color == red) // and its color is red
      {
        return (this->parent->parent->left);
      }
      // anything else
      return NULL;
    }

    Node* black_triangle_check() {
      // uncle is on the left and forms a triangle
      if (this->parent->right == this && // you're a right child
          this->parent->parent &&   // grandparent exists
          this->parent->parent->right && // grandparent has a left child
          this->parent->parent->right != this->parent && // that left child isn't your parent (uncle)
          this->parent->parent->right->color == black) // and its color is black
      {
        return (this->parent->parent->left);
      } 
      // uncle is on the right, and forms a triangle
      else if (this->parent->left == this && // you're a right child
               this->parent->parent &&  // grandparent exists
               this->parent->left &&   // grandparent has a right child
               this->parent->left != this->parent && // that right child isn't your parent (uncle)
               this->parent->parent->left->color == black) // and it's color is black
      {
        return (this->parent->parent->right);
      }
      // anything else
      return NULL;
    }

    void recolor() {
      if (this->color == black) {
        this->color = red;
        return;
      } 
      this->color = black;
    }

    int key;
    Color color;
    Node* parent;
    Node* left;
    Node* right;
};

#endif // NODE_H_