#include <iostream>

#include "observer.h"

int main() {
  ConcreteSubject* s = new ConcreteSubject();
  ConcreteObserver* o1 = new ConcreteObserver("X", s);
  ConcreteObserver* o2 = new ConcreteObserver("Y", s);
  ConcreteObserver* o3 = new ConcreteObserver("Z", s);
  s->Attach(o1);
  s->Attach(o2);
  s->Attach(o3);
  s->Detach(o3);

  s->status = "ABC";
  s->Notify();

  delete s;
  delete o1;
  delete o2;
  delete o3;

  return 0;
}
