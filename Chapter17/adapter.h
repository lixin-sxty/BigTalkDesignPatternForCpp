#ifndef ADAPTER_H_
#define ADAPTER_H_

#include <string>
#include <stdint.h>

class Player {
 public:
  Player(const std::string& name) : name(name) {}
  virtual ~Player() = default;
  virtual void Attack() const = 0;
  virtual void Defense() const = 0;

 protected:
  std::string name;
};

class Forwards : public Player {
 public:
  Forwards(const std::string& name) : Player(name) {}
  void Attack() const override;
  void Defense() const override;
};

class Center : public Player {
 public:
  Center(const std::string& name) : Player(name) {}
  void Attack() const override;
  void Defense() const override;
};

class Guards : public Player {
 public:
  Guards(const std::string& name) : Player(name) {}
  void Attack() const override;
  void Defense() const override;
};

class ForeignCenter {
 public:
  ForeignCenter(const std::string& name) : name(name) {}
  void attack() const;
  void defense() const;

 private:
  std::string name;
};

class Translator : public Player {
 public:
  Translator(const std::string& name) : Player(name), f(name) {}
  void Attack() const override;
  void Defense() const override;

 private:
  ForeignCenter f;
};

#endif  // ADAPTER_H_