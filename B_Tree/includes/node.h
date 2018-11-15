#ifndef NODE_H_
#define NODE_H_

#include <utility>
#include <algorithm>

static const int CAPACITY = 3;
static const int t = (CAPACITY + 1) / 2; // 2

class Node {

 public:
    Node() {
        std::fill_n(keys, CAPACITY, -1);
        for (int i = 0; i < CAPACITY+1; i++) { children[i] = NULL; }
        leaf = false;
        n = -1;
    }
    
    bool isFull() { return (n == CAPACITY); }

    int keys[CAPACITY];
    Node* children[CAPACITY+1];
    bool leaf;
    int n;

    
};

#endif // NODE_H_