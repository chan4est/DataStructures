#include "node.h"
#include <iostream>

class LinkedList {

 public:
  LinkedList() : head(NULL), size(0) {};

  // O(n) insert - complete trash
  void insert(int key) {
    Node* new_node = new Node(key);
    Node* temp = head;
    for (int i = 1; i < size; i++) {
      temp = temp->next;
    }
    if (temp == NULL) { 
       this->head = new_node;
    } else {
      temp->next = new_node;
    }
    size++;
  }

  void remove(int location) {
    if (location < 0 || location > size || this->head == NULL) {
      std::cout << "Out of bounds" << std::endl;
      return;
    }
    Node* temp = this->head;
    Node* prev = NULL;
    for (int i = 0; i < location; i++) {
      prev = temp;
      temp = temp->next;
    }
    if (prev == NULL) {
      this->head = temp->next;
    } else {
      prev->next = temp->next;
    }
    delete(temp);
    size--;
  }

  void print() {
    Node* temp = this->head;
    for (int i = 0; i < size; i++) {
      if (i == size-1) {
        std::cout << temp->key << " -> NULL" << std::endl;
        break;
      }
      std::cout << temp->key << " -> ";
      temp = temp->next;
    }
    if (temp == NULL) {
      std::cout << "[]" << std::endl;
    }
  }

  Node* head;
  int size;
};