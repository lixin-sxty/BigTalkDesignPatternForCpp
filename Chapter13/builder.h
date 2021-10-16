#ifndef BUILDER_H_
#define BUILDER_H_

#include <string>
#include <vector>

class Product {
 public:
  void Add(const std::string& part);
  void Show() const;

 private:
  std::vector<std::string> parts;
};

class Builder {
 public:
  virtual ~Builder() = default;
  virtual void BuildPartA() = 0;
  virtual void BuildPartB() = 0;
  Product GetResult() const;

 protected:
  Product product;
};

class ConcreteBuilder1 : public Builder {
 public:
  void BuildPartA() override;
  void BuildPartB() override;
};

class ConcreteBuilder2 : public Builder {
 public:
  void BuildPartA() override;
  void BuildPartB() override;
};

class Director {
 public:
  void Construct(Builder* b);
};

#endif  // BUILDER_H_