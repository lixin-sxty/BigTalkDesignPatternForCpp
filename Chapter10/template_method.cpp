#include "template_method.h"

#include <iostream>
#include <stdexcept>

void TestPaper::Question1() {
  std::cout << "Question 1: answer " << Answer1() << "\n";
}

void TestPaper::Question2() {
  std::cout << "Question 2: answer " << Answer2() << "\n";
}

void TestPaper::Question3() {
  std::cout << "Question 3: answer " << Answer3() << "\n";
}

void StudentA::PringName() { std::cout << "name: Mike\n"; }

std::string StudentA::Answer1() { return "a"; }

std::string StudentA::Answer2() { return "b"; }

std::string StudentA::Answer3() { return "c"; }

void StudentB::PringName() { std::cout << "name: Tom\n"; }

std::string StudentB::Answer1() { return "d"; }

std::string StudentB::Answer2() { return "c"; }

std::string StudentB::Answer3() { return "a"; }