#include "decorator.h"

#include <iostream>
#include <stdexcept>

Person::Person(std::string name) {
  name_ = name;
  std::cout << "Create Person.\n";
};

Person::~Person() { std::cout << "Delete Person.\n"; };

void Person::Show() { std::cout << "dressed " << name_ << ".\n"; };

Finery::Finery() { std::cout << "Create Finery.\n"; }

Finery::~Finery() { std::cout << "Delete Finery and "; }

void Finery::Decorate(Person* component) { component_ = component; }

void Finery::Show() {
  if (component_) {
    component_->Show();
  }
}

void Tshirt::Show() {
  std::cout << "Tshirt ";
  Finery::Show();
}

void BigTrouser::Show() {
  std::cout << "BigTrouser ";
  Finery::Show();
}

void Snearkers::Show() {
  std::cout << "Snearkers ";
  Finery::Show();
}

void LeatherShoes::Show() {
  std::cout << "LeatherShoes ";
  Finery::Show();
}

void Tie::Show() {
  std::cout << "Tie ";
  Finery::Show();
}

void Suit::Show() {
  std::cout << "Suit ";
  Finery::Show();
}