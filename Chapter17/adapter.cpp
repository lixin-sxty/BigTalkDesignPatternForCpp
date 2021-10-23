#include "adapter.h"

#include <iostream>

void Forwards::Attack() const {
  std::cout << "Forward " << name << " attack!\n";
}

void Forwards::Defense() const {
  std::cout << "Forward " << name << " defense!\n";
}

void Center::Attack() const { std::cout << "Center " << name << " attack!\n"; }

void Center::Defense() const {
  std::cout << "Center " << name << " defense!\n";
}

void Guards::Attack() const { std::cout << "Guards " << name << " attack!\n"; }

void Guards::Defense() const {
  std::cout << "Guards " << name << " defense!\n";
}

void ForeignCenter::attack() const {
  std::cout << "ForeignCenter " << name << " attack!\n";
}

void ForeignCenter::defense() const {
  std::cout << "ForeignCenter " << name << " defense!\n";
}

void Translator::Attack() const { f.attack(); }

void Translator::Defense() const { f.defense(); }