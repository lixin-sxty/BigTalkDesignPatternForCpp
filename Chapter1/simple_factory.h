#ifndef SIMPLE_FACTORY_H
#define SIMPLE_FACTORY_H

#include <string>

// base class
class Operation {
 protected:
  double _numberA = 0;
  double _numberB = 0;

 public:
  Operation();
  virtual ~Operation();

  double GetA() const;
  void SetA(double);
  double GetB() const;
  void SetB(double);
  virtual double GetResult();
};

class OperatorFactory {
 public:
  // Only support '+', '-', '*', '/'
  static Operation* createOperate(const std::string& type);
};
#endif  // SIMPLE_FACTORY_H