#ifndef DECORATOR_H_
#define DECORATOR_H_

#include <string>

class Person {
 public:
  Person() = default;
  Person(std::string name);
  virtual ~Person();

  virtual void Show();

 private:
  std::string name_;
};

class Finery : public Person {
 public:
  Finery();
  virtual ~Finery();

  void Decorate(Person* component);
  void Show() override;

 protected:
  Person* component_;
};

class Tshirt : public Finery {
 public:
  void Show() override;
};

class BigTrouser : public Finery {
 public:
  void Show() override;
};

class Snearkers : public Finery {
 public:
  void Show() override;
};

class LeatherShoes : public Finery {
 public:
  void Show() override;
};

class Tie : public Finery {
 public:
  void Show() override;
};

class Suit : public Finery {
 public:
  void Show() override;
};

#endif  // DECORATOR_H_