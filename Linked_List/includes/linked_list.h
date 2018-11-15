#include "node.h"
#include <iostream>
#include <vector>

class LinkedList {

 public:
  LinkedList() : head(NULL), size(0) {};

  // O(n) insert - complete trash
  void append(int key) {
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

  int& operator [](int index) {
    Node* temp = head;
    for (int i = 1; i < index; i++) {
      temp = temp->next;
    }
    return temp->key;
  }

  bool insert_at_index(int key, int index) {
    if (index < 0 || index > size || this->head == NULL)
      return false;
    Node* new_node = new Node(key);
    Node* temp = head;
    Node* prev = NULL;
    for (int i = 1; i < index; i++) {
      prev = temp;
      temp = temp->next;
    }
    if (prev == NULL) {
      this->head->next = new_node;
    } else {
      prev->next = new_node;
      new_node->next = temp;
    }
    return true;
  }

  int find_first_index_of(int key) {
    Node* temp = head;
    for (int i = 1; i < size; i++) {
      if (temp->key == key)
        return i-1;
      temp = temp->next;
    }
    return -1;
  }

  bool delete_at_index(int index) {
    if (index < 0 || index > size || this->head == NULL)
      return false;
    Node* temp = this->head;
    Node* prev = NULL;
    for (int i = 0; i < index; i++) {
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
    return true;
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