#include "../includes/stack.h"

int main(int argc, char** argv) {
  Stack s;
  s.push(1);
  s.push(3);
  s.push(5);
  s.push(100);
  s.push(-1);
  s.print();
  s.pop();
  std::cout << s.top() << std::endl;
}
