#include "iterator.h"

#include <iostream>

class ConcreteIterator : public Iterator {
 public:
  ConcreteIterator(Aggregate* agge) : aggregate(agge) {}
  std::string First() override { return (*aggregate)[0]; }
  std::string Next() override {
    if (++current < aggregate->Count()) {
      return (*aggregate)[current];
    } else {
      return "";
    }
  }
  bool IsDone() override { return current >= aggregate->Count(); }
  std::string Current() override {
    if (current < aggregate->Count()) {
      return (*aggregate)[current];
    } else {
      return "";
    }
  }

 private:
  Aggregate* aggregate;
  size_t current = 0;
};

ConcreteAggregate::ConcreteAggregate(size_t n)
    : items(std::vector<std::string>(n)) {}

Iterator* ConcreteAggregate::CreateIterator() {
  return new ConcreteIterator(this);
}

size_t ConcreteAggregate::Count() const { return items.size(); }

std::string ConcreteAggregate::operator[](size_t i) {
  if (i < items.size()) {
    return items[i];
  } else {
    return "";
  }
}

void ConcreteAggregate::Insert(size_t i, const std::string s) {
  if (i < items.size()) {
    items[i] = s;
  }
}
