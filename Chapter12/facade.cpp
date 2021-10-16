#include "facade.h"

#include <iostream>
#include <stdexcept>

class Stock1 {
 public:
  void Sell() { std::cout << "Sell stock1.\n"; }
  void Buy() { std::cout << "Buy stock1.\n"; }
};

class Stock2 {
 public:
  void Sell() { std::cout << "Sell stock2.\n"; }
  void Buy() { std::cout << "Buy stock2.\n"; }
};

class Stock3 {
 public:
  void Sell() { std::cout << "Sell stock3.\n"; }
  void Buy() { std::cout << "Buy stock3.\n"; }
};

class NationDebt1 {
 public:
  void Sell() { std::cout << "Sell nationDebt1.\n"; }
  void Buy() { std::cout << "Buy nationDebt1.\n"; }
};

class Realty1 {
 public:
  void Sell() { std::cout << "Sell realty1.\n"; }
  void Buy() { std::cout << "Buy realty1.\n"; }
};

Fund::Fund() {
  s1 = new Stock1();
  s2 = new Stock2();
  s3 = new Stock3();
  n1 = new NationDebt1();
  r1 = new Realty1();
}

Fund::~Fund() {
  delete s1;
  delete s2;
  delete s3;
  delete n1;
  delete r1;
}

void Fund::Buy() {
  s1->Buy();
  s2->Buy();
  s3->Buy();
  n1->Buy();
  r1->Buy();
}

void Fund::Sell() {
  s1->Sell();
  s2->Sell();
  s3->Sell();
  n1->Sell();
  r1->Sell();
}