#pragma once
#include <string>
#include <vector>
#include <queue>

class Event {
private:
    std::string eventID;
    std::string name;
    std::string date;
    std::string time;
    std::string location;
    int capacity;
    std::vector<std::string> participants;
    std::queue<std::string> waitlist;
    bool isApproved;

public:
    Event(const std::string& id, const std::string& name,
          const std::string& date, const std::string& time,
          const std::string& location, int capacity);

    bool addParticipant(const std::string& userID);
    bool addToWaitlist(const std::string& userID);
    bool isFull() const;

    std::string getEventID() const { return eventID; }
    std::string getName() const { return name; }
    std::string getDate() const { return date; }
    std::string getTime() const { return time; }
    std::string getLocation() const { return location; }
    int getCurrentCapacity() const { return static_cast<int>(participants.size()); }
    int getMaxCapacity() const { return capacity; }
    bool getApproved() const { return isApproved; }
    bool setApproved(bool approved);
    int getWaitlistSize() const { return static_cast<int>(waitlist.size()); }
};
