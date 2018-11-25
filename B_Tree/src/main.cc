#include "../includes/b_tree.h"

int main(int argc, char** argv) {
  BTree* tree = new BTree(2);
  tree->insert(10);
  tree->insert(20);
  tree->insert(5);
  tree->insert(6);
  tree->insert(12);
  tree->insert(30);
  tree->insert(7);
  tree->insert(17);
  tree->traverse();
  std::cout << '\n';
}
