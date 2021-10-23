#include "abstract_factory.h"

#include <iostream>

class SqlserverDepartment : public Department {
 public:
  void Insert() override {
    std::cout << "SQL:Insert a message in Department table.\n";
  }
};

class AccessDepartment : public Department {
 public:
  void Insert() override {
    std::cout << "Access:Insert a message in Department table.\n";
  }
};

class SqlserverUser : public User {
 public:
  void Insert() override {
    std::cout << "SQL:Insert a message in User table.\n";
  }
};

class AccessUser : public User {
 public:
  void Insert() override {
    std::cout << "Access:Insert a message in User table.\n";
  }
};

User* SqlServerFactory::CreateUser() { return new SqlserverUser(); }

Department* SqlServerFactory::CreateDepartment() {
  return new SqlserverDepartment();
}

User* AccessFactory::CreateUser() { return new AccessUser(); }

Department* AccessFactory::CreateDepartment() { return new AccessDepartment(); }
