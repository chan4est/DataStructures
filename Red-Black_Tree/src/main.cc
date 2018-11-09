#include "../includes/red_black_tree.h"

int main(int argc, char** argv) {
  RedBlackTree* rb = new RedBlackTree();
  rb->insert(50);
  rb->insert(60);
  rb->insert(70);
  rb->print();
}
