#include "factory_method.h"

#include <iostream>
#include <stdexcept>

class Undergraduate : public LeiFeng {
 public:
  Undergraduate() { people_ = "Undergraduate"; }
};

class Volunteer : public LeiFeng {
 public:
  Volunteer() { people_ = "Volunteer"; }
};

void LeiFeng::Sweep() { std::cout << people_ << " sweep\n"; }

void LeiFeng::Wash() { std::cout << people_ << " wash\n"; }

void LeiFeng::BuyRice() { std::cout << people_ << " buy rice\n"; }

LeiFeng* UndergraduateFactory::CreateLeiFeng() { return new Undergraduate(); }

LeiFeng* VolunteerFactory::CreateLeiFeng() { return new Volunteer(); }