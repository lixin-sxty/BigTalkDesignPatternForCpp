#include "command.h"

#include <iostream>

void Barbecuer::BakeMutton() const { std::cout << "bake mutton!\n"; }

void Barbecuer::BakeChicken() const { std::cout << "bake chicken!\n"; }

void BakeMuttonCommand::ExcuteCommand() const { receiver->BakeMutton(); }

std::string BakeMuttonCommand::ToString() const { return "BakeMutton"; }

void BakeChickenCommand::ExcuteCommand() const { receiver->BakeChicken(); }

std::string BakeChickenCommand::ToString() const { return "BakeChicken"; }

Waiter::~Waiter() {
  for (auto c : commands) {
    delete c;
    c = nullptr;
  }
}

void Waiter::AddOrder(Command* c) {
  auto str = c->ToString();
  if (str == "BakeChicken") {
    std::cout << "Do not have chicken, please select other.\n";
    return;
  }
  std::cout << "Add order:" << str << "\n";
  commands.push_back(c);
}

void Waiter::RemoveOrder(Command* c) {
  std::cout << "Remove order:" << c->ToString() << "\n";
  for (auto it = commands.begin(); it != commands.end();) {
    if (*it == c) {
      it = commands.erase(it);
    } else {
      ++it;
    }
  }
}

void Waiter::Notify() const {
  for (auto c : commands) {
    c->ExcuteCommand();
  }
}