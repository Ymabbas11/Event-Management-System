#pragma once
#include <string>
#include <map>

class IRoom {
public:
    virtual ~IRoom() = default;
    
    // Core room operations
    virtual bool reserve(const std::string& date) = 0;
    virtual bool release(const std::string& date) = 0;
    virtual bool checkAvailability(const std::string& date) const = 0;
    
    // Getters
    virtual std::string getRoomID() const = 0;
    virtual std::string getBuilding() const = 0;
    virtual std::string getFloor() const = 0;
    virtual int getCapacity() const = 0;
    virtual std::string getDescription() const = 0;
}; 