#ifndef FACTORY_METHOD_H_
#define FACTORY_METHOD_H_

#include <string>

class LeiFeng {
 public:
  virtual ~LeiFeng(){};

  void Sweep();
  void Wash();
  void BuyRice();

 protected:
  std::string people_;
};

class IFactory {
 public:
  virtual ~IFactory(){};

  virtual LeiFeng* CreateLeiFeng() = 0;
};

class UndergraduateFactory : public IFactory {
 public:
  LeiFeng* CreateLeiFeng() override;
};

class VolunteerFactory : public IFactory {
 public:
  LeiFeng* CreateLeiFeng() override;
};

#endif  // FACTORY_METHOD_H_