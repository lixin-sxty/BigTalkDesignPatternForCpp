#ifndef SINGLETON_H_
#define SINGLETON_H_

#include <string>
#include <stdint.h>
#include <vector>
#include <mutex>

// lazy mode singleton
class LazySingleton {
 public:
  static LazySingleton* GetInstance();
  ~LazySingleton() { delete p; }
  void show();

 private:
  static LazySingleton* p;
  LazySingleton() = default;
};

// Meyers singleton, only used in C++11 and later
class MeyersSingleton {
 public:
  static MeyersSingleton& GetInstance();
  void show();

 private:
  MeyersSingleton() = default;
};

// eager mode singleton
class EagerSingleton {
 public:
  static EagerSingleton& GetInstance();
  void show();

 private:
  // Create when program init.
  static EagerSingleton instance;
  EagerSingleton() = default;
};

#endif  // SINGLETON_H_