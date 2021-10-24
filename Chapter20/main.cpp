#include <iostream>

#include "iterator.h"

int main() {
  Aggregate* a = new ConcreteAggregate(6);

  a->Insert(0, "A");
  a->Insert(1, "B");
  a->Insert(2, "C");
  a->Insert(3, "D");
  a->Insert(4, "E");
  a->Insert(5, "F");

  Iterator* i = a->CreateIterator();
  while (!i->IsDone()) {
    std::cout << i->Current() << ", please but ticket!\n";
    i->Next();
  }

  delete a;
  delete i;

  return 0;
}
