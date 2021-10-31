#ifndef RESPONSIBILITY_CHAIN_H_
#define RESPONSIBILITY_CHAIN_H_

#include <string>
#include <vector>

enum class RequestType : uint8_t { ask_for_leave = 0, pay_rise };

struct Request {
  RequestType type;
  uint32_t number;
  std::string content;
};

class Manager {
 public:
  Manager(const std::string& name) : name(name) {}
  void SetSuperior(Manager* m);
  virtual void RequestApplications(const Request& req) = 0;
  virtual ~Manager() = default;

 protected:
  void Approve(const Request& req) const;
  void NotApprove(const Request& req) const;
  std::string name;
  Manager* superior;
};

class CommonManager : public Manager {
 public:
  CommonManager(const std::string& name) : Manager(name) {}
  void RequestApplications(const Request& req) override;
};

class Majordomo : public Manager {
 public:
  Majordomo(const std::string& name) : Manager(name) {}
  void RequestApplications(const Request& req) override;
};

class GeneralManager : public Manager {
 public:
  GeneralManager(const std::string& name) : Manager(name) {}
  void RequestApplications(const Request& req) override;
};

#endif  // RESPONSIBILITY_CHAIN_H_