#include "../includes/linked_list.h"

int main(int argc, char** argv) {
  LinkedList* ll = new LinkedList();
  ll->insert(10);
  ll->remove(0);
  ll->print();
  ll->insert(20);
  ll->insert(30);
  ll->print();
  ll->remove(1);
  ll->print();
}
