#ifndef NODE_H_
#define NODE_H_

#include <utility>

class Node {

 public:
    Node(int key) : key(key), next(NULL) {}
    int key;
    Node* next;
};

#endif // NODE_H_