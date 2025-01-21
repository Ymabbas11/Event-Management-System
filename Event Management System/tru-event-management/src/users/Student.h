#pragma once
#include "User.h"

class Student : public User {
public:
    Student(const std::string& id, const std::string& name, const std::string& email);
    
    bool login() override;
    void viewEvents() override;
    bool registerForEvent(const std::string& eventID) override;
    bool joinWaitlist(const std::string& eventID);
}; 