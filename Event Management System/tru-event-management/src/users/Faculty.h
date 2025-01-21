#pragma once
#include "User.h"
#include "Event.h"

class Faculty : public User {
public:
    Faculty(const std::string& id, const std::string& name, const std::string& email);
    
    bool login() override;
    void viewEvents() override;
    bool registerForEvent(const std::string& eventID) override;
    
    Event* createEvent(const std::string& name, const std::string& date, 
                      const std::string& location, int capacity);
    bool manageEvent(const std::string& eventID);
}; 