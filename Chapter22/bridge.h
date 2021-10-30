#ifndef BRIDGE_H_
#define BRIDGE_H_

#include <string>
#include <vector>

class Software {
 public:
  virtual ~Software() = default;
  virtual void Run() = 0;
};

class Game : public Software {
 public:
  void Run() override;
};

class AddressList : public Software {
 public:
  void Run() override;
};

class Mp3 : public Software {
 public:
  void Run() override;
};

class Phone {
 public:
  virtual ~Phone();
  virtual void Run();
  void AddSoft(Software* s);

 protected:
  std::vector<Software*> soft;
};

class PhoneM : public Phone {
 public:
  void Run() override;
};

class PhoneN : public Phone {
 public:
  void Run() override;
};

#endif  // BRIDGE_H_