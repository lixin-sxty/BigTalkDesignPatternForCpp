#include <iostream>

#include "bridge.h"

int main() {
  Phone* m = new PhoneM();
  m->AddSoft(new Game());
  m->AddSoft(new AddressList());
  m->AddSoft(new Mp3());
  m->Run();

  Phone* n = new PhoneN();
  n->AddSoft(new Game());
  n->AddSoft(new AddressList());
  n->AddSoft(new Mp3());
  n->Run();

  delete m;
  delete n;

  return 0;
}
