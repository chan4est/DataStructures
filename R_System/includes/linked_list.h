#include <iostream>
#include <vector>

class ListNode {

 public:
    ListNode(int key) : key(key), next(NULL) {}
    int key;
    ListNode* next;
};

class LinkedList {

 public:
  LinkedList() : head(NULL), size(0) {};

  // O(n) insert - complete trash
  void append(int key) {
    ListNode* new_node = new ListNode(key);
    ListNode* temp = head;
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
    ListNode* temp = head;
    for (int i = 1; i < index; i++) {
      temp = temp->next;
    }
    return temp->key;
  }

  bool insert_at_index(int key, int index) {
    if (index < 0 || index > size || this->head == NULL)
      return false;
    ListNode* new_node = new ListNode(key);
    ListNode* temp = head;
    ListNode* prev = NULL;
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
    ListNode* temp = head;
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
    ListNode* temp = this->head;
    ListNode* prev = NULL;
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
    ListNode* temp = this->head;
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

  ListNode* head;
  int size;
};