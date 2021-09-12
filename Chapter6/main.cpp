#include <iostream>

#include "decorator.h"

int main() {
  auto p = new Person("mike");

  std::cout << "The first dress up:\n";

  auto snearkers = new Snearkers();
  auto big_trouser = new BigTrouser();
  auto tshirt = new Tshirt();

  snearkers->Decorate(p);
  big_trouser->Decorate(snearkers);
  tshirt->Decorate(big_trouser);

  tshirt->Show();

  std::cout << "\nThe second dress up:\n";

  auto leather_shoes = new LeatherShoes();
  auto tie = new Tie();
  auto suit = new Suit();

  leather_shoes->Decorate(p);
  tie->Decorate(leather_shoes);
  suit->Decorate(tie);

  suit->Show();

  delete p;
  delete snearkers;
  delete big_trouser;
  delete tshirt;
  delete leather_shoes;
  delete tie;
  delete suit;

  return 0;
}
