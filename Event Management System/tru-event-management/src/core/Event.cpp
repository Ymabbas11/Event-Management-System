#include "Event.h"

Event::Event(const std::string& id, const std::string& n,
             const std::string& d, const std::string& t,
             const std::string& loc, int cap)
    : eventID(id), name(n), date(d), time(t), location(loc),
      capacity(cap), isApproved(false) {
}

bool Event::addParticipant(const std::string& userID) {
    if (!isApproved) {
        return false;  // Can't register for unapproved events
    }
    if (isFull()) {
        return false;
    }
    participants.push_back(userID);
    return true;
}

bool Event::addToWaitlist(const std::string& userID) {
    if (!isApproved) {
        return false;  // Can't join waitlist for unapproved events
    }
    waitlist.push(userID);
    return true;
}

bool Event::isFull() const {
    return static_cast<int>(participants.size()) >= capacity;
}

bool Event::setApproved(bool approved) {
    isApproved = approved;
    return true;
}
