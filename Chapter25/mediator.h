#ifndef MEDIATOR_H_
#define MEDIATOR_H_

#include <string>
#include <vector>

class UnitedNations;

class Country {
 public:
  Country(UnitedNations* m, const std::string name);
  void GetMessage(const std::string& message);
  std::string GetName();
  void Declare(const std::string& message);
  virtual ~Country(){};

 protected:
  UnitedNations* mediator;
  std::string name;
};

class USA : public Country {
 public:
  USA(UnitedNations* m) : Country(m, "USA"){};
};

class Iraq : public Country {
 public:
  Iraq(UnitedNations* m) : Country(m, "Iraq"){};
};

class UnitedNations {
 public:
  virtual ~UnitedNations() {}
  virtual void Declare(const std::string& message, Country* colleague) = 0;
};

class UNSC : public UnitedNations {
 public:
  void Declare(const std::string& message, Country* colleague) override;
  void SetC1(Country* c);
  void SetC2(Country* c);

 private:
  Country* c1;
  Country* c2;
};

#endif  // MEDIATOR_H_