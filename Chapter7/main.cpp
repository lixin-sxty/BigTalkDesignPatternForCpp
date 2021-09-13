#include <iostream>

#include "proxy.h"

int main() {
  Girl girl("Lili");

  Proxy mike(girl);

  mike.GiveDolls();
  mike.GiveFlowers();
  mike.GiveChocolate();

  return 0;
}
