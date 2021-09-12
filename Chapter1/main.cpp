#include <iostream>

#include "simple_factory.h"

int main() {
  double a = 3;
  double b = 5;
  std::cout << "a = " << a << ", b = " << b << '\n';

  auto add = OperatorFactory::createOperate("+");
  add->SetA(a);
  add->SetB(b);
  std::cout << "a + b = " << add->GetResult() << '\n';

  auto sub = OperatorFactory::createOperate("-");
  sub->SetA(a);
  sub->SetB(b);
  std::cout << "a - b = " << sub->GetResult() << '\n';

  auto mul = OperatorFactory::createOperate("*");
  mul->SetA(a);
  mul->SetB(b);
  std::cout << "a * b = " << mul->GetResult() << '\n';

  auto div = OperatorFactory::createOperate("/");
  div->SetA(a);
  div->SetB(b);
  std::cout << "a / b = " << div->GetResult() << '\n';

  delete add;
  delete sub;
  delete mul;
  delete div;

  return 0;
}
