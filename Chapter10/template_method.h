#ifndef FACTORY_METHOD_H_
#define FACTORY_METHOD_H_

#include <string>

class TestPaper {
 public:
  virtual ~TestPaper() = default;
  void Question1();
  void Question2();
  void Question3();
  virtual void PringName() = 0;

 private:
  virtual std::string Answer1() = 0;
  virtual std::string Answer2() = 0;
  virtual std::string Answer3() = 0;
};

class StudentA : public TestPaper {
 public:
  void PringName() override;

 private:
  std::string Answer1() override;
  std::string Answer2() override;
  std::string Answer3() override;
};

class StudentB : public TestPaper {
 public:
  void PringName() override;

 private:
  std::string Answer1() override;
  std::string Answer2() override;
  std::string Answer3() override;
};

#endif  // FACTORY_METHOD_H_