#include "../includes/r_system.h"

int main(int argc, char* argv[]) {
  R_System* sys = new R_System(argc, argv);
  auto t = sys->tree;
  t->insert(8);
  t->insert(10);
  t->insert(14);
  t->insert(6);
  t->insert(12);
  t->print();
  
  // sys->start();
}
