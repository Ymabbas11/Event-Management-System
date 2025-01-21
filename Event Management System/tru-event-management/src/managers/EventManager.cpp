#include "EventManager.h"
#include "Event.h"
#include "BookingManager.h"
#include <algorithm>
#include <stdexcept>

EventManager::EventManager(BookingManager* bManager) : bookingManager(bManager) {}

EventManager::~EventManager() {
    for (auto iter = events.begin(); iter != events.end(); ++iter) {
        delete iter->second;
    }
    events.clear();
}

std::string EventManager::scheduleEvent(const std::string& name,
                                        const std::string& date,
                                        const std::string& time,
                                        const std::string& location,
                                        int capacity,
                                        const std::string& organizerID) {
    if (hasScheduleConflict(date, time, location)) {
        throw std::runtime_error("Schedule conflict detected.");
    }

    std::string eventID = "EVT" + std::to_string(events.size() + 1);
    Event* newEvent = new Event(eventID, name, date, time, location, capacity);
    events[eventID] = newEvent;
    return eventID;
}

Event* EventManager::getEvent(const std::string& eventID) const {
    auto it = events.find(eventID);
    if (it != events.end()) {
        return it->second;
    }
    return nullptr;
}

std::vector<Event*> EventManager::getPendingEvents() const {
    std::vector<Event*> pendingEvents;
    for (const auto& pair : events) {
        if (!pair.second->getApproved()) {
            pendingEvents.push_back(pair.second);
        }
    }
    return pendingEvents;
}

std::vector<Event*> EventManager::getApprovedEvents() const {
    std::vector<Event*> approvedEvents;
    for (const auto& pair : events) {
        if (pair.second->getApproved()) {
            approvedEvents.push_back(pair.second);
        }
    }
    return approvedEvents;
}

std::vector<Event*> EventManager::getAllEvents() const {
    std::vector<Event*> allEvents;
    for (const auto& pair : events) {
        allEvents.push_back(pair.second);
    }
    return allEvents;
}

bool EventManager::hasScheduleConflict(const std::string& date, const std::string& time, const std::string& location) const {
    for (auto iter = events.begin(); iter != events.end(); ++iter) {
        if (iter->second->getDate() == date && 
            iter->second->getTime() == time && 
            iter->second->getLocation() == location) {
            return true;
        }
    }
    return false;
}
