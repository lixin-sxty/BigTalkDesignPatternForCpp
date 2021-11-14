#include <iostream>

#include "mediator.h"

int main() {
  UNSC* unsc = new UNSC();
  Country* usa = new USA(unsc);
  Country* iraq = new Iraq(unsc);

  unsc->SetC1(usa);
  unsc->SetC2(iraq);

  usa->Declare("Do not develop nuclear weapons or start a war!");
  iraq->Declare(
      "We do not have nuclear weapons and we are not afraid of aggression!");

  delete unsc;
  delete usa;
  delete iraq;

  return 0;
}
