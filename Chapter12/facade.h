#ifndef FACADE_H_
#define FACADE_H_

#include <string>

class Stock1;
class Stock2;
class Stock3;
class NationDebt1;
class Realty1;

class Fund {
 public:
  Fund();
  ~Fund();
  void Sell();
  void Buy();

 private:
  Stock1* s1;
  Stock2* s2;
  Stock3* s3;
  NationDebt1* n1;
  Realty1* r1;
};

#endif  // FACADE_H_