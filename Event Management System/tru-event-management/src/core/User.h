#pragma once
#include <string>

class User {
protected:
    std::string userID;
    std::string name;
    std::string role;
    std::string email;

public:
    User(const std::string& id, const std::string& name, const std::string& email);
    virtual ~User() = default;

    virtual bool login() = 0;
    virtual void viewEvents() = 0;
    virtual bool registerForEvent(const std::string& eventID) = 0;

    // Getters
    std::string getUserID() const { return userID; }
    std::string getName() const { return name; }
    std::string getRole() const { return role; }
    std::string getEmail() const { return email; }
}; 