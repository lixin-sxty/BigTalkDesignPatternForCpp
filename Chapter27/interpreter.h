#ifndef INTERPRETER_H_
#define INTERPRETER_H_

#include <string>
#include <vector>
#include <queue>

using PlayContent = std::queue<std::string>;

class Expression {
 public:
  virtual ~Expression() {}
  virtual void Interpret(PlayContent& content) = 0;
  virtual void Excute(const std::string& key, int val) = 0;
};

class Note : public Expression {
 public:
  void Interpret(PlayContent& content) override;
  void Excute(const std::string& key, int) override;
};

class Scale : public Expression {
 public:
  void Interpret(PlayContent& content) override;
  void Excute(const std::string&, int val) override;
};

#endif  // INTERPRETER_H_