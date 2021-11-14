#include <iostream>

#include "interpreter.h"

int main() {
  PlayContent cont;
  cont.push("O");
  cont.push("2");
  cont.push("E");
  cont.push("G");
  cont.push("A");
  cont.push("E");
  cont.push("G");
  cont.push("D");
  cont.push("E");
  cont.push("G");
  cont.push("A");
  cont.push("O");
  cont.push("3");
  cont.push("C");
  cont.push("O");
  cont.push("2");
  cont.push("A");
  cont.push("G");
  cont.push("C");
  cont.push("E");
  cont.push("D");
  std::cout << "Music:\n";
  Expression* exp = nullptr;
  while (!cont.empty()) {
    delete exp;
    if (cont.front() == "O") {
      exp = new Scale();
    } else {
      exp = new Note();
    }
    exp->Interpret(cont);
  }
  std::cout << "\n";
  delete exp;
  return 0;
}
