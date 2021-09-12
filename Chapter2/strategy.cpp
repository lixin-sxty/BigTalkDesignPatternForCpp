#include "strategy.h"

#include <stdexcept>

class CashSuper {
 public:
  virtual double acceptCash(double money) = 0;
  virtual ~CashSuper(){};
};

class CashNormal : public CashSuper {
 public:
  double acceptCash(double money) override { return money; }
};

class CashRebate : public CashSuper {
 public:
  CashRebate(double rebate) : money_rebate_(rebate) {}
  double acceptCash(double money) override { return money * money_rebate_; }

 private:
  double money_rebate_ = 1.0;
};

class CashReturn : public CashSuper {
 public:
  CashReturn(double condition, double money_return)
      : money_condition_(condition), money_return_(money_return) {}

  double acceptCash(double money) override {
    if (money >= money_condition_) {
      money = money -
              static_cast<uint32_t>(money / money_condition_) * money_return_;
    }
    return money;
  }

 private:
  double money_condition_ = 0.0;
  double money_return_ = 0.0;
};

CashContext::CashContext(const std::string& type) {
  // C++ do not support string in switch-case, use if-else instead
  // Switch string to int using hash function is better.
  if (type == "normal") {
    cs = new CashNormal();
  } else if (type == "8_rebate") {
    cs = new CashRebate(0.8);
  } else if (type == "300_minus_100") {
    cs = new CashReturn(300, 100);
  } else {
    throw std::runtime_error("Unsupport type:" + type);
  }
}

CashContext::~CashContext() { delete cs; }

double CashContext::GetResult(double money) { return cs->acceptCash(money); }