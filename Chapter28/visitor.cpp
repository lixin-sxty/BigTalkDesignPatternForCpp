#include "visitor.h"

#include <iostream>

std::string Person::GetName() const { return name; }

void Man::Accept(Action* visitor) { visitor->GetManConclusion(this); }

void Woman::Accept(Action* visitor) { visitor->GetWomanConclusion(this); }

void Success::GetManConclusion(Man* m) {
  std::cout << m->GetName() << ", " << name
            << ": man's conclusion for Success\n";
}

void Success::GetWomanConclusion(Woman* w) {
  std::cout << w->GetName() << ", " << name
            << ": woman's conclusion for Success\n";
}

void Failing::GetManConclusion(Man* m) {
  std::cout << m->GetName() << ", " << name
            << ": man's conclusion for Failing\n";
}

void Failing::GetWomanConclusion(Woman* w) {
  std::cout << w->GetName() << ", " << name
            << ": woman's conclusion for Failing\n";
}

void Amativeness::GetManConclusion(Man* m) {
  std::cout << m->GetName() << ", " << name
            << ": man's conclusion for Amativeness\n";
}

void Amativeness::GetWomanConclusion(Woman* w) {
  std::cout << w->GetName() << ", " << name
            << ": woman's conclusion for Amativeness\n";
}