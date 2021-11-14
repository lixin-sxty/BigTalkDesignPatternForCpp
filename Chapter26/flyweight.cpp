#include "flyweight.h"

#include <iostream>

void ConcreteWebsite::use(const User& user) {
  std::cout << "Website type:" << name << ", user:" << user.name << "\n";
}

Website* WebsiteFactory::GetWebsite(const std::string& key) {
  if (!flyweights.count(key)) {
    flyweights[key] = new ConcreteWebsite(key);
  }
  return flyweights[key];
}

int WebsiteFactory::GetWebsiteCount() { return flyweights.size(); }

WebsiteFactory::~WebsiteFactory() {
  for (auto it = flyweights.begin(); it != flyweights.end(); ++it) {
    delete it->second;
  }
}