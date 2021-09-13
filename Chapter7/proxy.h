#ifndef PROXY_H_
#define PROXY_H_

#include <string>

class Girl {
 public:
  Girl(std::string name) : name_(name){};

  std::string GetName() { return name_; };

 private:
  std::string name_;
};

class GiveGift {
 public:
  virtual ~GiveGift(){};

  virtual void GiveDolls() = 0;
  virtual void GiveFlowers() = 0;
  virtual void GiveChocolate() = 0;
};

class Pursuit;

class Proxy : public GiveGift {
 public:
  Proxy(Girl mm);
  ~Proxy();

  void GiveDolls() override;
  void GiveFlowers() override;
  void GiveChocolate() override;

 private:
  Pursuit* gg_ = nullptr;
};

#endif  // PROXY_H_