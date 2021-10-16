#ifndef OBSERVER_H_
#define OBSERVER_H_

#include <string>
#include <unordered_set>

class Observer;

class Subject {
 public:
  virtual ~Subject() = default;
  void Attach(Observer*);
  void Detach(Observer*);
  void Notify() const;

 private:
  std::unordered_set<Observer*> observers;
};

class ConcreteSubject : public Subject {
 public:
  std::string status;
};

class Observer {
 public:
  virtual ~Observer() = default;
  virtual void Update() = 0;
};

class ConcreteObserver : public Observer {
 public:
  ConcreteObserver(const std::string& name, ConcreteSubject* sub);
  void Update() override;

 private:
  std::string name;
  ConcreteSubject* sub;
};

#endif  // OBSERVER_H_