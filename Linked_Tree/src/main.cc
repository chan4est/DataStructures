#include "../includes/linked_tree.h"

int main(int argc, char** argv) {
  LinkedTree* lt = new LinkedTree();
  lt->append(NULL, 5);
  Node* head = lt->head;
  lt->append(head, 33);
  lt->append(head, 17);
  lt->append(head, 2);
  lt->append(head, 1);
  head->child = new Node(6);
  lt->append(head->child, 25);
  lt->append(head->child, 6);
  head->child->next->child = new Node(8);
  head->child->next->next->child = new Node(9);
  head->child->next->next->child->child = new Node(7);
  auto n = head->next->next->next;
  n->child = new Node(2);
  lt->append(n->child, 7);
  n->child->child = new Node(12);
  lt->append(n->child->child, 5);
  n = n->child->child;
  n->child = new Node(21);
  lt->append(n->child, 3);
  lt->flatten_tree();
  lt->print(lt->head);
}
