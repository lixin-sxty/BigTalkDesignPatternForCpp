#include <iostream>

#include "flyweight.h"

int main() {
  WebsiteFactory f;
  Website* fx = f.GetWebsite("display");
  fx->use(User("A"));
  Website* fy = f.GetWebsite("display");
  fy->use(User("B"));
  Website* fz = f.GetWebsite("display");
  fz->use(User("C"));
  Website* fl = f.GetWebsite("blog");
  fl->use(User("D"));
  Website* fm = f.GetWebsite("blog");
  fm->use(User("E"));
  Website* fn = f.GetWebsite("blog");
  fn->use(User("F"));

  std::cout << "Website number:" << f.GetWebsiteCount() << "\n";

  return 0;
}
