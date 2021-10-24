#ifndef ITERATOR_H_
#define ITERATOR_H_

#include <string>
#include <stdint.h>
#include <vector>

class Iterator {
 public:
  virtual ~Iterator() = default;
  virtual std::string First() = 0;
  virtual std::string Next() = 0;
  virtual bool IsDone() = 0;
  virtual std::string Current() = 0;
};

class Aggregate {
 public:
  virtual ~Aggregate() = default;
  virtual Iterator* CreateIterator() = 0;
  virtual size_t Count() const = 0;
  virtual std::string operator[](size_t) = 0;
  virtual void Insert(size_t i, const std::string s) = 0;
};

class ConcreteAggregate : public Aggregate {
 public:
  ConcreteAggregate(size_t n);
  Iterator* CreateIterator() override;
  size_t Count() const override;
  std::string operator[](size_t) override;
  void Insert(size_t i, const std::string s) override;

 private:
  std::vector<std::string> items;
};

#endif  // ITERATOR_H_