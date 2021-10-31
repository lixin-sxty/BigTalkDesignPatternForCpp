#include <iostream>

#include "command.h"

int main() {
  Barbecuer* b = new Barbecuer();
  Command* bake_muttom_1 = new BakeMuttonCommand(b);
  Command* bake_muttom_2 = new BakeMuttonCommand(b);
  Command* bake_chicken_1 = new BakeChickenCommand(b);
  Waiter w;

  w.AddOrder(bake_muttom_1);
  w.AddOrder(bake_muttom_2);
  w.AddOrder(bake_chicken_1);

  w.Notify();

  delete b;

  return 0;
}
