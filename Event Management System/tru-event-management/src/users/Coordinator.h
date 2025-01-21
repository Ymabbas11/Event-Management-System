#pragma once
#include "User.h"
#include <string>
#include <vector>

class EventManager;
class Event;

class Coordinator : public User {
public:
    Coordinator(const std::string& id, const std::string& name, const std::string& email);

    bool login() override;
    void viewEvents() override;
    bool registerForEvent(const std::string& eventID) override;

    bool approveEvent(const std::string& eventID, EventManager* eventManager);
};
