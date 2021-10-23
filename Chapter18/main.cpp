#include <iostream>

#include "memento.h"

int main() {
  // before fight
  Role x;
  x.Display();

  // save
  StateCaretaker admin;
  admin.SetMemento(x.SaveState());

  // fight
  x.fight();
  x.Display();

  // recovery
  x.RecoveryState(admin.GetMemento());
  x.Display();

  return 0;
}
