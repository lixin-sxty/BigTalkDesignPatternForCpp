#include <iostream>

#include "prototype.h"

int main() {
  auto p1 = new Resume("li", 20, "A");

  auto p2 = p1->Clone();
  p2->SetWorkExperience("B");

  auto p3 = p2->Clone();
  p3->SetName("tom");

  auto p4 = p3->Clone();
  p4->SetAge(25);

  p1->Display();
  p2->Display();
  p3->Display();
  p4->Display();

  delete p1;
  delete p2;
  delete p3;
  delete p4;

  return 0;
}
