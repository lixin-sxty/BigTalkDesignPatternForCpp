#ifndef COMMAND_H_
#define COMMAND_H_

#include <string>
#include <vector>

class Barbecuer {
 public:
  void BakeMutton() const;
  void BakeChicken() const;
};

class Command {
 public:
  Command(Barbecuer* r) : receiver(r) {}
  virtual ~Command() = default;
  virtual void ExcuteCommand() const = 0;
  virtual std::string ToString() const = 0;

 protected:
  Barbecuer* receiver;
};

class BakeMuttonCommand : public Command {
 public:
  BakeMuttonCommand(Barbecuer* r) : Command(r) {}
  void ExcuteCommand() const override;
  std::string ToString() const override;
};

class BakeChickenCommand : public Command {
 public:
  BakeChickenCommand(Barbecuer* r) : Command(r) {}
  void ExcuteCommand() const override;
  std::string ToString() const override;
};

class Waiter {
 public:
  ~Waiter();
  void AddOrder(Command* c);
  void RemoveOrder(Command* c);
  void Notify() const;

 private:
  std::vector<Command*> commands;
};

#endif  // COMMAND_H_