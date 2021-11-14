#include <iostream>

#include "visitor.h"

int main() {
  Action* success = new Success();
  Action* failing = new Failing();
  Action* amativeness = new Amativeness();

  Man man;
  Woman woman;

  man.Accept(success);
  man.Accept(failing);
  man.Accept(amativeness);

  woman.Accept(success);
  woman.Accept(failing);
  woman.Accept(amativeness);

  delete success;
  delete failing;
  delete amativeness;

  return 0;
}
