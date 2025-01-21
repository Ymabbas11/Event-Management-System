#pragma once
#include "IRoom.h"

class ConferenceRoom : public IRoom {
private:
    std::string roomID;
    std::string building;
    std::string floor;
    int capacity;
    bool hasProjector;
    bool hasVideoConference;
    std::map<std::string, bool> availabilitySchedule;

public:
    ConferenceRoom(const std::string& id, const std::string& bldg, int cap,
                  bool projector = true, bool videoConf = true);
    ~ConferenceRoom() override = default;

    // Room interface implementation
    bool reserve(const std::string& date) override;
    bool release(const std::string& date) override;
    bool checkAvailability(const std::string& date) const override;

    std::string getRoomID() const override { return roomID; }
    std::string getBuilding() const override { return building; }
    std::string getFloor() const override { return floor; }
    int getCapacity() const override { return capacity; }
    std::string getDescription() const override;

    // Additional conference room specific methods
    bool hasProjectorSystem() const { return hasProjector; }
    bool hasVideoConferencing() const { return hasVideoConference; }
};
