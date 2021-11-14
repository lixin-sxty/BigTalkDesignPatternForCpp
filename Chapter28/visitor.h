#ifndef VISITOR_H_
#define VISITOR_H_

#include <string>
#include <vector>
#include <queue>

class Action;

class Person {
 public:
  Person(const std::string& name) : name(name) {}
  virtual ~Person() {}
  virtual void Accept(Action* visitor) = 0;
  std::string GetName() const;

 protected:
  std::string name;
};

class Man : public Person {
 public:
  Man() : Person("Man") {}
  void Accept(Action* visitor) override;
};

class Woman : public Person {
 public:
  Woman() : Person("Woman") {}
  void Accept(Action* visitor) override;
};

class Action {
 public:
  Action(const std::string& name) : name(name) {}
  virtual ~Action() {}
  virtual void GetManConclusion(Man* m) = 0;
  virtual void GetWomanConclusion(Woman* w) = 0;

 protected:
  std::string name;
};

class Success : public Action {
 public:
  Success() : Action("Success") {}
  void GetManConclusion(Man* m) override;
  void GetWomanConclusion(Woman* w) override;
};

class Failing : public Action {
 public:
  Failing() : Action("Failing") {}
  void GetManConclusion(Man* m) override;
  void GetWomanConclusion(Woman* w) override;
};

class Amativeness : public Action {
 public:
  Amativeness() : Action("Amativeness") {}
  void GetManConclusion(Man* m) override;
  void GetWomanConclusion(Woman* w) override;
};

#endif  // VISITOR_H_