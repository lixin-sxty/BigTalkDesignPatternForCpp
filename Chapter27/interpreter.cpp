#include "interpreter.h"

#include <iostream>

void Note::Interpret(PlayContent& content) {
  if (content.empty()) {
    return;
  }
  std::string key = content.front();
  content.pop();
  Excute(key, 0);
}

void Note::Excute(const std::string& key, int) {
  int32_t note = (key[0] - 'B');
  note = note > 0 ? note : note + 7;
  std::cout << note << " ";
}

void Scale::Interpret(PlayContent& content) {
  if (content.empty()) {
    return;
  }
  std::string key = content.front();
  content.pop();
  int val = std::stoi(content.front());
  content.pop();
  Excute(key, val);
}

void Scale::Excute(const std::string&, int val) {
  std::string scale;
  switch (val) {
    case 1:
      scale = "low";
      break;
    case 2:
      scale = "mid";
      break;
    case 3:
      scale = "high";
      break;
    default:
      break;
  }
  std::cout << scale << " ";
}