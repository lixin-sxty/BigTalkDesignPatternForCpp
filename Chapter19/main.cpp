#include <iostream>

#include "composite.h"

int main() {
  ConcreteCompany* root = new ConcreteCompany("beijing");
  root->Add(new HRDepartment("beijing HR"));
  root->Add(new FinanceDepartment("beijing finance"));

  ConcreteCompany* comp = new ConcreteCompany("shanghai");
  comp->Add(new HRDepartment("shanghai HR"));
  comp->Add(new FinanceDepartment("shanghai finance"));
  root->Add(comp);

  ConcreteCompany* comp1 = new ConcreteCompany("nanjing");
  comp1->Add(new HRDepartment("nanjing HR"));
  comp1->Add(new FinanceDepartment("nanjing finance"));
  comp->Add(comp1);

  ConcreteCompany* comp2 = new ConcreteCompany("hangzhou");
  comp2->Add(new HRDepartment("hangzhou HR"));
  comp2->Add(new FinanceDepartment("hangzhou finance"));
  comp->Add(comp2);

  std::cout << "Graph of struct:\n";
  root->Display(1);

  std::cout << "Duty:\n";
  root->Duty();

  delete root;

  return 0;
}
