#include "responsibility_chain.h"

#include <iostream>

void Manager::SetSuperior(Manager* m) { superior = m; }

void Manager::Approve(const Request& req) const {
  std::cout << name << ":" << req.content << ", number " << req.number
            << " is approved.\n";
}

void Manager::NotApprove(const Request& req) const {
  std::cout << name << ":" << req.content << ", number " << req.number
            << " is not approved.\n";
}

void CommonManager::RequestApplications(const Request& req) {
  if (req.type == RequestType::ask_for_leave && req.number <= 2) {
    Approve(req);
  } else {
    if (superior != nullptr) {
      superior->RequestApplications(req);
    }
  }
}

void Majordomo::RequestApplications(const Request& req) {
  if (req.type == RequestType::ask_for_leave && req.number <= 5) {
    Approve(req);
  } else {
    if (superior != nullptr) {
      superior->RequestApplications(req);
    }
  }
}

void GeneralManager::RequestApplications(const Request& req) {
  if (req.type == RequestType::ask_for_leave) {
    Approve(req);
  } else {
    if (req.number <= 500) {
      Approve(req);
    } else {
      NotApprove(req);
    }
  }
}