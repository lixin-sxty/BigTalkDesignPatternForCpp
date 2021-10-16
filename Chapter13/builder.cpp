#include "builder.h"

#include <iostream>
#include <stdexcept>

void Product::Add(const std::string& part) { parts.emplace_back(part); }

void Product::Show() const {
  std::cout << "Product construct:\n";
  for (auto p : parts) {
    std::cout << p << "\n";
  }
  std::cout << "Product construct successd!\n";
}

Product Builder::GetResult() const { return product; }

void ConcreteBuilder1::BuildPartA() { product.Add("part A."); }

void ConcreteBuilder1::BuildPartB() { product.Add("part B."); }

void ConcreteBuilder2::BuildPartA() { product.Add("part X."); }

void ConcreteBuilder2::BuildPartB() { product.Add("part Y."); }

void Director::Construct(Builder* b) {
  b->BuildPartA();
  b->BuildPartB();
}
