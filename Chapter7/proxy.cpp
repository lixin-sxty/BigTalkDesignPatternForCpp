#include "proxy.h"

#include <iostream>
#include <stdexcept>

class Pursuit : public GiveGift {
 public:
  Pursuit(Girl mm) : mm_(mm) {}

  void GiveDolls() override {
    std::cout << mm_.GetName() << ", I'll give you a doll.\n";
  }

  void GiveFlowers() override {
    std::cout << mm_.GetName() << ", I'll give you some flowers.\n";
  }

  void GiveChocolate() override {
    std::cout << mm_.GetName() << ", I'll give you a chocolate.\n";
  };

 private:
  Girl mm_;
};

Proxy::Proxy(Girl mm) { gg_ = new Pursuit(mm); }

Proxy::~Proxy() { delete gg_; }

void Proxy::GiveDolls() { gg_->GiveDolls(); }

void Proxy::GiveFlowers() { gg_->GiveFlowers(); }

void Proxy::GiveChocolate() { gg_->GiveChocolate(); }