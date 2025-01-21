#include "Room.h"

Room::Room(const std::string& id, const std::string& bldg, int cap)
    : roomID(id), building(bldg), capacity(cap) {
    // Extract floor from roomID
    if (roomID.length() >= 3) {
        if (roomID.substr(0, 2) == "OM") {
            floor = roomID.substr(2, 1);  // For OM rooms, take the first digit after OM
        } else if (roomID.substr(0, 2) == "HL") {
            floor = roomID.substr(2, 1);  // For HL rooms, take the first digit after HL
        }
    }
}

bool Room::reserve(const std::string& date) {
    if (!checkAvailability(date)) {
        return false;
    }
    availabilitySchedule[date] = false;
    return true;
}

bool Room::release(const std::string& date) {
    auto it = availabilitySchedule.find(date);
    if (it == availabilitySchedule.end()) {
        return false;
    }
    it->second = true;
    return true;
}

bool Room::checkAvailability(const std::string& date) const {
    auto it = availabilitySchedule.find(date);
    return (it == availabilitySchedule.end()) || it->second;
}

std::string Room::getDescription() const {
    return roomID + " - " + building + " (" + floor + "), Capacity: "
           + std::to_string(capacity);
}
