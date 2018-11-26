#ifndef R_SYSTEM_H_
#define R_SYSTEM_H_

#include "./b_tree.h"
#include "./graph.h"
#include "./user.h"

class R_System {

 public:
  R_System(int argc, char* argv[]) {
    tree = new BTree(2);
    graph = new Graph();   
  }

  void start() {
    while (true) {
      // run dialog options here...
      // std::cout << "Hello World" << std::endl;
    }
  }

  void input_file() {
    // need to parse name, perm, genre1, genre2, and friend ID's
    // User curr = new User(name, perm, genre1, genre2);
    // graph->add_node(perm);
    // while (there are friends) {
    //   graph->add_friendship(perm, friend_perms);
    // }
  }

  void add_user() {

  }

  void find_user() {

  }

  void find_user_details() {

  }

  void recommend_friends() {

  }

  BTree* tree;
  Graph* graph;
};

#endif // R_SYSTEM_H_