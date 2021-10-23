#ifndef STATE_H_
#define STATE_H_

#include <string>
#include <stdint.h>

class State;

class Work {
 public:
  Work();
  ~Work();
  int32_t GetTime() const { return hour; }
  bool GetFinish() const { return finish; }
  void SetTime(int32_t t);
  void SetFinish(bool b);
  void SetState(State* s);
  void WriteCode();

 private:
  int32_t hour = 0;
  bool finish = false;
  State* current;
};

#endif  // STATE_H_