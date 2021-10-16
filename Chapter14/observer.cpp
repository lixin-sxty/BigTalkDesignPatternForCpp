#include "observer.h"

#include <iostream>
#include <stdexcept>

void Subject::Attach(Observer* ob) { observers.insert(ob); }

void Subject::Detach(Observer* ob) { observers.erase(ob); }

void Subject::Notify() const {
  for (auto each : observers) {
    each->Update();
  }
}

ConcreteObserver::ConcreteObserver(const std::string& name,
                                   ConcreteSubject* sub)
    : name(name), sub(sub) {}

void ConcreteObserver::Update() {
  std::cout << "observer " << name << " status: " << sub->status << "\n";
}