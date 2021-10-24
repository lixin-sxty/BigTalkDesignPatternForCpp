#ifndef COMPOSITE_H_
#define COMPOSITE_H_

#include <string>
#include <stdint.h>
#include <set>

class Company {
 public:
  virtual ~Company() = default;
  Company(const std::string& name) : name(name) {}
  virtual void Add(Company* c) { delete c; }
  virtual void Remove(Company* c) { delete c; }
  virtual void Display(uint8_t depth) const;
  virtual void Duty() const = 0;

 protected:
  std::string name;
};

class ConcreteCompany : public Company {
 public:
  ConcreteCompany(const std::string& name) : Company(name) {}
  ~ConcreteCompany();
  void Add(Company* c) override;
  void Remove(Company* c) override;
  void Display(uint8_t depth) const override;
  void Duty() const override;

 private:
  std::set<Company*> children;
};

class HRDepartment : public Company {
 public:
  HRDepartment(const std::string& name) : Company(name) {}
  void Duty() const override;
};

class FinanceDepartment : public Company {
 public:
  FinanceDepartment(const std::string& name) : Company(name) {}
  void Duty() const override;
};

#endif  // COMPOSITE_H_