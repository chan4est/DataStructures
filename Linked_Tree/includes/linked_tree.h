#include "node.h"
#include <iostream>
#include <vector>

class LinkedTree {

 public:
  LinkedTree() : head(NULL) {};

  // O(n) insert - complete trash
  void append(Node* head , int key) {
    if (this->head == NULL) {
      this->head = new Node(key);
      return;
    }
    Node* prev = NULL;
    while (head->next != NULL) {
      head = head->next;
    }
    head->next = new Node(key);
    head->next->prev = head;
  }

  void flatten_tree() {
    Node* temp = head;
    while (temp != NULL) {
      if (temp->child) {
        Node* child_head = temp->child;
        if (temp->next) {
            Node* temp_next = temp->next;
            Node* child_tail = temp->child;
            while (child_tail->next != NULL) {
                child_tail = child_tail->next;
            }
            // set all the pointers correctly
            temp->next = child_head;
            temp->next->prev = temp;
            child_tail->next = temp_next;
            child_tail->next->prev = child_tail;
        } else {
            temp->next = child_head;
            temp->next->prev = temp;
        }
        temp->child = NULL;
      }
      temp = temp->next;
    }
  }

  void print(Node* head) {
    while (head != NULL) {
      std::cout << head->key << " ";
      head = head->next;
    }
  }

  Node* head;
};