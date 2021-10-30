#include "singleton.h"

#include <iostream>

std::mutex mtx;

LazySingleton* LazySingleton::p = nullptr;

LazySingleton* LazySingleton::GetInstance() {
  // double check lock
  if (p == nullptr) {
    std::lock_guard<std::mutex> m(mtx);
    if (p == nullptr) {
      p = new LazySingleton();
    }
  }
  return p;
}

void LazySingleton::show() {
  std::cout << "This is a LazySingleton instance.\n";
}

MeyersSingleton& MeyersSingleton::GetInstance() {
  static MeyersSingleton instance;
  return instance;
}

void MeyersSingleton::show() {
  std::cout << "This is a MeyersSingleton instance.\n";
}

EagerSingleton EagerSingleton::instance;

EagerSingleton& EagerSingleton::GetInstance() { return instance; }

void EagerSingleton::show() {
  std::cout << "This is a EagerSingleton instance.\n";
}
