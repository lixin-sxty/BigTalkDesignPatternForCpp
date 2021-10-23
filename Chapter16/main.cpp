#include <iostream>

#include "state.h"

int main() {
  Work w;
  w.SetTime(9);
  w.WriteCode();
  w.SetTime(10);
  w.WriteCode();
  w.SetTime(12);
  w.WriteCode();
  w.SetTime(13);
  w.WriteCode();
  w.SetTime(14);
  w.WriteCode();
  w.SetTime(17);

  // w.SetFinish(true);
  w.SetFinish(false);

  w.WriteCode();
  w.SetTime(19);
  w.WriteCode();
  w.SetTime(22);
  w.WriteCode();

  return 0;
}
