#include <iostream>

#include "strategy.h"

int main() {
  double money = 1000;
  std::cout << "origin money:" << money << "\n";

  CashContext ctx1("normal");
  std::cout << "normal strategy:" << ctx1.GetResult(money) << "\n";

  CashContext ctx2("8_rebate");
  std::cout << "8_rebate strategy:" << ctx2.GetResult(money) << "\n";

  CashContext ctx3("300_minus_100");
  std::cout << "300_minus_100 strategy:" << ctx3.GetResult(money) << "\n";

  return 0;
}
