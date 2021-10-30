#include "bridge.h"

#include <iostream>

void Game::Run() { std::cout << "Run soflware:Game.\n"; }

void AddressList::Run() { std::cout << "Run soflware:AddressList.\n"; }

void Mp3::Run() { std::cout << "Run soflware:Mp3.\n"; }

Phone::~Phone() {
  for (auto p : soft) {
    delete p;
    p = nullptr;
  }
}

void Phone::AddSoft(Software* s) { soft.push_back(s); }

void Phone::Run() {
  for (auto p : soft) {
    p->Run();
  }
}

void PhoneM::Run() {
  std::cout << "Phone M:\n";
  Phone::Run();
}

void PhoneN::Run() {
  std::cout << "Phone N:\n";
  Phone::Run();
}