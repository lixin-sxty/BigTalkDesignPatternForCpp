#include <iostream>

#include "builder.h"

int main() {
  Director d;
  Builder* b1 = new ConcreteBuilder1();
  Builder* b2 = new ConcreteBuilder2();

  d.Construct(b1);
  Product p1 = b1->GetResult();
  p1.Show();

  d.Construct(b2);
  Product p2 = b2->GetResult();
  p2.Show();

  delete b1;
  delete b2;

  return 0;
}
