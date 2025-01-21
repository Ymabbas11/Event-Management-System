#pragma once
#include "IRoom.h"
#include <stdexcept>

class Room : public IRoom {
private:
    std::string roomID;
    std::string building;
    std::string floor;
    int capacity;
    std::map<std::string, bool> availabilitySchedule;

    friend class RoomFactory;

    Room(const std::string& id, const std::string& bldg, int cap);

public:
    ~Room() override = default;
=
    bool reserve(const std::string& date) override;
    bool release(const std::string& date) override;
    bool checkAvailability(const std::string& date) const override;

    std::string getRoomID() const override { return roomID; }
    std::string getBuilding() const override { return building; }
    std::string getFloor() const override { return floor; }
    int getCapacity() const override { return capacity; }
    std::string getDescription() const override;
};
