#include "state.h"

#include <iostream>

class State {
 public:
  virtual ~State() = default;
  virtual void WirteCode(Work* w) = 0;
};

class RestState : public State {
  void WirteCode(Work* w) override {
    std::cout << "Current time:" << w->GetTime() << ", go home.\n";
  }
};

class SleepState : public State {
  void WirteCode(Work* w) override {
    std::cout << "Current time:" << w->GetTime() << ", state 0.\n";
  }
};

class EveningState : public State {
  void WirteCode(Work* w) override {
    if (w->GetFinish()) {
      w->SetState(new RestState());
      w->WriteCode();
    } else {
      if (w->GetTime() < 21) {
        std::cout << "Current time:" << w->GetTime() << ", state 20.\n";
      } else {
        w->SetState(new SleepState());
        w->WriteCode();
      }
    }
  }
};

class AfternoonState : public State {
  void WirteCode(Work* w) override {
    if (w->GetTime() < 17) {
      std::cout << "Current time:" << w->GetTime() << ", state 60.\n";
    } else {
      w->SetState(new EveningState());
      w->WriteCode();
    }
  }
};

class NoonState : public State {
  void WirteCode(Work* w) override {
    if (w->GetTime() < 13) {
      std::cout << "Current time:" << w->GetTime() << ", state 80.\n";
    } else {
      w->SetState(new AfternoonState());
      w->WriteCode();
    }
  }
};

class ForenoonState : public State {
  void WirteCode(Work* w) override {
    if (w->GetTime() < 12) {
      std::cout << "Current time:" << w->GetTime() << ", state 100.\n";
    } else {
      w->SetState(new NoonState());
      w->WriteCode();
    }
  }
};

Work::Work() : current(new ForenoonState()) {}

Work::~Work() { delete current; }

void Work::SetTime(int32_t t) { hour = t; }

void Work::SetFinish(bool b) { finish = b; }

void Work::SetState(State* s) {
  delete current;
  current = s;
}

void Work::WriteCode() { current->WirteCode(this); }