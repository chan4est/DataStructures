#include "node.h"
#include <iostream>
#include <vector>

class Stack {

 public:
  Stack() : stack_top(NULL) {};

  // O(1) insert - complete trash
  void push(int value) {
    Node* new_node = new Node(value);
    new_node->next = stack_top;
    stack_top = new_node;
  }

  void pop() {
    if (stack_top) {
      Node* temp = stack_top;
      stack_top = stack_top -> next;
      delete(temp);
    }
  }

  int top() {
    return stack_top->key;
  }

  void print() {
    Node* temp = stack_top;
    std::cout << "[ ";
    while (temp) {
      if (temp->next == NULL) {
        std::cout << temp->key;
      } else {
        std::cout << temp->key << " | ";
      }
      temp = temp->next;
    }
    std::cout << " ]" << std::endl;
  }

  Node* stack_top;
};