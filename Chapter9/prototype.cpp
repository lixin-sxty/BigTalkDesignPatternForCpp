#include "prototype.h"

#include <iostream>
#include <stdexcept>

class Work {
 public:
  Work(std::string company) { company_ = company; }
  std::string GetName() const { return company_; }

 private:
  std::string company_;
};

Resume::Resume(const std::string& name, const uint8_t& age,
               const std::string& work_experience)
    : name_(name), age_(age), work_experience_(new Work(work_experience)) {}

Resume::~Resume() { delete work_experience_; }

Resume* Resume::Clone() {
  auto* p = new Resume(*this);
  // deep copy of pointer member
  p->work_experience_ = new Work(*this->work_experience_);
  return p;
}

void Resume::Display() {
  printf("%s, age of %d, worked at company %s\n", name_.c_str(), age_,
         work_experience_->GetName().c_str());
}

void Resume::SetName(const std::string& name) { name_ = name; }

void Resume::SetAge(const uint8_t& age) { age_ = age; }

void Resume::SetWorkExperience(const std::string& work_experience) {
  delete work_experience_;
  work_experience_ = new Work(work_experience);
}