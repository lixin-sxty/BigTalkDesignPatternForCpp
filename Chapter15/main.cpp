#include <iostream>

#include "abstract_factory.h"

int main() {
  Factory* f1 = new SqlServerFactory();
  User* u1 = f1->CreateUser();
  Department* d1 = f1->CreateDepartment();
  u1->Insert();
  d1->Insert();

  Factory* f2 = new AccessFactory();
  User* u2 = f2->CreateUser();
  Department* d2 = f2->CreateDepartment();
  u2->Insert();
  d2->Insert();

  delete f1;
  delete u1;
  delete d1;
  delete f2;
  delete u2;
  delete d2;

  return 0;
}
