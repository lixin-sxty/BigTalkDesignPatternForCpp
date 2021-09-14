#include <iostream>

#include "factory_method.h"

int main() {
  IFactory* undergrad_factory = new UndergraduateFactory();
  auto student = undergrad_factory->CreateLeiFeng();

  student->Wash();
  student->Sweep();
  student->BuyRice();

  delete student;
  delete undergrad_factory;

  IFactory* volunteer_factory = new VolunteerFactory();
  auto volunteer = volunteer_factory->CreateLeiFeng();

  volunteer->Wash();
  volunteer->Sweep();
  volunteer->BuyRice();

  delete volunteer;
  delete volunteer_factory;

  return 0;
}
