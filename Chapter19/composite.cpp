#include "composite.h"

#include <iostream>

ConcreteCompany::~ConcreteCompany() {
  for (auto it = children.begin(); it != children.end(); it++) {
    delete *it;
  }
}

void Company::Display(uint8_t depth) const {
  std::cout << std::string(depth, '-') << name << "\n";
}

void ConcreteCompany::Add(Company* c) { children.insert(c); }

void ConcreteCompany::Remove(Company* c) { children.erase(c); }

void ConcreteCompany::Display(uint8_t depth) const {
  std::cout << std::string(depth, '-') << name << "\n";
  for (auto& c : children) {
    c->Display(depth + 1);
  }
}

void ConcreteCompany::Duty() const {
  for (auto& c : children) {
    c->Duty();
  }
}

void HRDepartment::Duty() const { std::cout << name << " HR duty.\n"; }

void FinanceDepartment::Duty() const { std::cout << name << " Finance duty.\n"; }
