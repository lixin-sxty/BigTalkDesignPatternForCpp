#ifndef MEMENTO_H_
#define MEMENTO_H_

#include <string>
#include <stdint.h>

class StateMemento;

class Role {
 public:
  void Display() const;
  void fight();
  StateMemento* SaveState();
  void RecoveryState(StateMemento* s);

 private:
  uint32_t vit = 100;
  uint32_t atk = 100;
  uint32_t def = 100;
};

class StateCaretaker {
 public:
  ~StateCaretaker();
  void SetMemento(StateMemento* s);
  StateMemento* GetMemento();

 private:
  StateMemento* memento = nullptr;
};

#endif  // MEMENTO_H_