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

    int black_uncle_check() {
      // Left Left Case
      if (this->parent &&
          this->parent->left == this &&
          this->parent->parent &&
          this->parent->parent->left &&
          this->parent->parent->left == this->parent &&
         (this->parent->parent->right == NULL || this->parent->parent->color == black)) 
      {
        return(1);
      } 
      // Left Right Case
      else if (this->parent &&
               this->parent->right == this &&
               this->parent->parent &&
               this->parent->parent->left == this->parent &&
              (this->parent->parent->right == NULL || this->parent->parent->color == black)) 
      {
        return(2);
      }
      // Right Right Case
      else if (this->parent &&
               this->parent->right == this &&
               this->parent->parent &&               
               this->parent->parent->right == this->parent &&
              (this->parent->parent->left == NULL || this->parent->parent->left->color == black))
      {
        return(3);
      }
      // Right Left Case
      else if (this->parent &&
               this->parent->left == this &&
               this->parent->parent->right == this->parent &&
              (this->parent->parent->left == NULL || this->parent->parent->left->color == black))
      {
        return(4);
      } else {
        return(5);
      }
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