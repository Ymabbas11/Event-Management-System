#pragma once
#include <map>
#include <string>
#include <vector>
#include "Event.h"
#include "BookingManager.h"

class EventManager {
private:
    std::map<std::string, Event*> events;
    BookingManager* bookingManager;

public:
    EventManager(BookingManager* bookingManager);
    ~EventManager();

    std::string scheduleEvent(const std::string& name,
                            const std::string& date,
                            const std::string& time,
                            const std::string& location,
                            int capacity,
                            const std::string& organizerID);

    Event* getEvent(const std::string& eventID) const;
    std::vector<Event*> getPendingEvents() const;
    std::vector<Event*> getApprovedEvents() const;
    bool hasScheduleConflict(const std::string& date, const std::string& time, const std::string& location) const;

    std::vector<Event*> getAllEvents() const;
};
