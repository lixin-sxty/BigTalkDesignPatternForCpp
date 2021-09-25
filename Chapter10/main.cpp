#include <iostream>

#include "template_method.h"

int main() {
  TestPaper* s1 = new StudentA();
  s1->PringName();
  s1->Question1();
  s1->Question2();
  s1->Question3();

  TestPaper* s2 = new StudentB();
  s2->PringName();
  s2->Question1();
  s2->Question2();
  s2->Question3();

  delete s1;
  delete s2;

  return 0;
}
