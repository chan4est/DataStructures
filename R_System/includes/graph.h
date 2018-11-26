#ifndef GRAPH_H_
#define GRAPH_H_

#include <vector>
#include <algorithm>
#include "./linked_list.h"

class Graph {
  
 public:
  void add_node(int perm) {
    for (int i = 0; i < list.size(); i++) {
      if (list[i]->head->key == perm) {
        std::cout << "Trying to insert a dublicate ID into graph" << std::endl;
        return;
      }
    }
    auto ll = new LinkedList();
    ll->append(perm);
    list.push_back(ll);
  }
  
  void add_friend(int target_perm, int friend_perm) {
    for (int i = 0; i < list.size(); i++) {
      if (list[i]->head->key == target_perm) {
        list[i]->append(friend_perm);
        break;
      }
    }
  }

 private:
  std::vector<LinkedList*> list;
};

#endif // GRAPH_H_