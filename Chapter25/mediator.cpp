#include "mediator.h"

#include <iostream>

Country::Country(UnitedNations* m, const std::string name)
    : mediator(m), name(name) {}

void Country::GetMessage(const std::string& message) {
  std::cout << name << " get message: " << message << "\n";
}

std::string Country::GetName() { return name; }

void Country::Declare(const std::string& message) {
  std::cout << name << " declare: " << message << "\n";
  mediator->Declare(message, this);
}

void UNSC::Declare(const std::string& message, Country* colleague) {
  if (colleague == c1) {
    c2->GetMessage(message);
  } else if (colleague == c2) {
    c1->GetMessage(message);
  } else {
    std::runtime_error("Unsupport country.\n");
  }
}

void UNSC::SetC1(Country* c) { c1 = c; }

void UNSC::SetC2(Country* c) { c2 = c; }