#ifndef ABSTRACT_FACTORY_H_
#define ABSTRACT_FACTORY_H_

#include <string>

class User {
 public:
  virtual ~User() = default;
  virtual void Insert() = 0;
};

class Department {
 public:
  virtual ~Department() = default;
  virtual void Insert() = 0;
};

class Factory {
 public:
  virtual ~Factory() = default;
  virtual User* CreateUser() = 0;
  virtual Department* CreateDepartment() = 0;
};

class SqlServerFactory : public Factory {
 public:
  User* CreateUser() override;
  Department* CreateDepartment() override;
};

class AccessFactory : public Factory {
 public:
  User* CreateUser() override;
  Department* CreateDepartment() override;
};

#endif  // ABSTRACT_FACTORY_H_