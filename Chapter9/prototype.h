#ifndef FACTORY_METHOD_H_
#define FACTORY_METHOD_H_

#include <string>

class Work;

class Prototype {
 public:
  Prototype() = default;
  virtual ~Prototype() = default;

  // clone should implement as a Deep copy rather than shallow copy
  virtual Prototype* Clone() = 0;
  virtual void Display() = 0;
  virtual void SetName(const std::string& name) = 0;
  virtual void SetAge(const uint8_t& age) = 0;
  virtual void SetWorkExperience(const std::string& work_experience) = 0;
};

class Resume : public Prototype {
 public:
  Resume(const std::string& name, const uint8_t& age,
         const std::string& work_experience);
  ~Resume();

  Resume* Clone() override;
  void Display();
  void SetName(const std::string& name);
  void SetAge(const uint8_t& age);
  void SetWorkExperience(const std::string& work_experience);

 private:
  std::string name_;
  uint8_t age_;
  Work* work_experience_;
};

#endif  // FACTORY_METHOD_H_