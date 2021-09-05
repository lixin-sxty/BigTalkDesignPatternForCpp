#include <iostream>

#include "simple_factory.h"

int main() {
  auto op = OperatorFactory::createOperate("+");
  op->SetA(1);
  op->SetB(1);
  double r = op->GetResult();
  std::cout << r << '\n';
  return 0;
}
