#include <iostream>

#include "adapter.h"

int main() {
  Player* a = new Forwards("A");
  a->Attack();
  Player* b = new Guards("B");
  b->Attack();
  Player* c = new Translator("C");
  c->Attack();
  c->Defense();

  delete a;
  delete b;
  delete c;

  return 0;
}
