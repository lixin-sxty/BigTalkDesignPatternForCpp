#include <iostream>

#include "singleton.h"

int main() {
  auto a = LazySingleton::GetInstance();
  a->show();

  auto& b = MeyersSingleton::GetInstance();
  b.show();

  auto& c = EagerSingleton::GetInstance();
  c.show();

  return 0;
}
