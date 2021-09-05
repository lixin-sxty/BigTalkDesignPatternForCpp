#include "simple_factory.h"

#include <stdexcept>

double Operation::GetA() const { return _numberA; }

void Operation::SetA(double val) { _numberA = val; }

double Operation::GetB() const { return _numberB; }

void Operation::SetB(double val) { _numberB = val; }

double Operation::GetResult() { return 0; }

class OperationAdd : public Operation {
  double GetResult() override;
};

class OperationSub : public Operation {
  double GetResult() override;
};

class OperationMul : public Operation {
  double GetResult() override;
};

class OperationDiv : public Operation {
  double GetResult() override;
};

double OperationAdd::GetResult() { return _numberA + _numberB; }

double OperationSub::GetResult() { return _numberA - _numberB; }

double OperationMul::GetResult() { return _numberA * _numberB; }

double OperationDiv::GetResult() {
  if (_numberB == 0) {
    throw std::runtime_error("B can not be zeor in div operation.");
  }
  return _numberA / _numberB;
}

Operation* OperatorFactory::createOperate(const std::string& type) {
  Operation* oper;
  // C++ do not support string in switch-case, use if-else instead
  // Switch string to int using hash function is better.
  if (type == "+") {
    oper = new OperationAdd();
  } else if (type == "-") {
    oper = new OperationSub();
  } else if (type == "*") {
    oper = new OperationMul();
  } else if (type == "/") {
    oper = new OperationDiv();
  } else {
    throw std::runtime_error("Unsupport operation:" + type);
  }
  return oper;
}