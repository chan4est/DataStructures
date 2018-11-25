#ifndef NODE_H_
#define NODE_H_

#include <utility>

class Node {

 public:
    Node(int key) : key(key), next(NULL), prev(NULL), child(NULL) {}
    
    int key;
    Node* next;
    Node* prev;
    Node* child;
};

#endif // NODE_H_