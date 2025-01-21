#include "ConferenceRoom.h"

ConferenceRoom::ConferenceRoom(const std::string& id, const std::string& bldg, int cap,
                             bool projector, bool videoConf)
    : roomID(id), building(bldg), capacity(cap),
      hasProjector(projector), hasVideoConference(videoConf) {
    if (roomID.length() >= 3) {
        floor = roomID.substr(2, 1);
    }
}

bool ConferenceRoom::reserve(const std::string& date) {
    if (!checkAvailability(date)) {
        return false;
    }
    availabilitySchedule[date] = false;
    return true;
}

bool ConferenceRoom::release(const std::string& date) {
    auto it = availabilitySchedule.find(date);
    if (it != availabilitySchedule.end()) {
        availabilitySchedule.erase(it);
        return true;
    }
    return false;
}

bool ConferenceRoom::checkAvailability(const std::string& date) const {
    auto it = availabilitySchedule.find(date);
    return it == availabilitySchedule.end() || it->second;
}

std::string ConferenceRoom::getDescription() const {
    std::string features;
    if (hasProjector) features += " with projector";
    if (hasVideoConference) features += " with video conferencing";
    
    return "Conference Room " + roomID + " in " + building + " (Floor " + floor + 
           "), Capacity: " + std::to_string(capacity) + features;
} 