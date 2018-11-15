#include "../includes/linked_list.h"

int main(int argc, char** argv) {
  LinkedList* ll = new LinkedList();
  ll->append(10);
  ll->delete_at_index(0);
  ll->print();
  ll->append(20);
  ll->append(30);
  ll->print();
  ll->delete_at_index(1);
  ll->print();
}
