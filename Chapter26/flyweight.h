#ifndef FLYWEIGHT_H_
#define FLYWEIGHT_H_

#include <string>
#include <vector>
#include <unordered_map>

struct User {
  User(const std::string& n) : name(n) {}
  std::string name;
};

class Website {
 public:
  Website(const std::string& name) : name(name) {}
  virtual ~Website() {}
  virtual void use(const User& user) = 0;

 protected:
  std::string name;
};

class ConcreteWebsite : public Website {
 public:
  ConcreteWebsite(const std::string& name) : Website(name) {}
  void use(const User& user) override;
};

class WebsiteFactory {
 public:
  ~WebsiteFactory();
  Website* GetWebsite(const std::string& key);
  int GetWebsiteCount();

 private:
  std::unordered_map<std::string, Website*> flyweights;
};

#endif  // FLYWEIGHT_H_