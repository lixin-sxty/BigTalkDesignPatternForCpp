#include "memento.h"

#include <iostream>

struct StateMemento {
  StateMemento(int32_t v, int32_t a, int32_t d) : vit(v), atk(a), def(d) {}
  uint32_t vit;
  uint32_t atk;
  uint32_t def;
};

void Role::Display() const {
  std::cout << "Current state:\n"
            << "vit:" << vit << "\natk:" << atk << "\ndef:" << def << "\n";
}

void Role::fight() { vit = atk = def = 0; }

StateMemento* Role::SaveState() { return new StateMemento(vit, atk, def); }

void Role::RecoveryState(StateMemento* s) {
  vit = s->vit;
  atk = s->atk;
  def = s->def;
  delete s;
}

StateCaretaker::~StateCaretaker() { delete memento; }

StateMemento* StateCaretaker::GetMemento() {
  StateMemento* ret = memento;
  memento = nullptr;
  return ret;
}

void StateCaretaker::SetMemento(StateMemento* s) {
  delete memento;
  memento = s;
}