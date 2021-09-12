#ifndef STRATEGY_H_
#define STRATEGY_H_

#include <string>

class CashSuper;

class CashContext {
  CashSuper* cs = nullptr;

 public:
  // strategy support: "normal","8_rebate","300_minus_100"
  CashContext(const std::string& type);

  ~CashContext();

  double GetResult(double money);
};
#endif  // STRATEGY_H_