#include <iostream>

#include "responsibility_chain.h"

int main() {
  Manager* a = new CommonManager("CommonManager");
  Manager* b = new Majordomo("Majordomo");
  Manager* c = new GeneralManager("GeneralManager");
  a->SetSuperior(b);
  b->SetSuperior(c);

  Request req1{RequestType::ask_for_leave, 1, "ask for leave"};
  a->RequestApplications(req1);

  Request req2{RequestType::ask_for_leave, 4, "ask for leave"};
  a->RequestApplications(req2);

  Request req3{RequestType::pay_rise, 500, "pay rise"};
  a->RequestApplications(req3);

  Request req4{RequestType::pay_rise, 1000, "pay rise"};
  a->RequestApplications(req4);

  delete a;
  delete b;
  delete c;

  return 0;
}
