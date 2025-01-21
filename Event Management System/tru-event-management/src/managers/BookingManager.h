#pragma once
#include <map>
#include <string>
#include <vector>
#include "IRoom.h"
#include "RoomFactory.h"
#include "Event.h"

struct Booking {
    std::string bookingID;
    std::string eventID;
    std::string roomID;
    std::string date;
    bool isApproved;
};

class BookingManager {
private:
    std::map<std::string, Booking> bookings;
    std::map<std::string, IRoom*> rooms;

public:
    BookingManager();
    ~BookingManager();

    void addRoom(const std::string& roomID, const std::string& building, int capacity);
    std::string createBooking(const std::string& eventID,
                            const std::string& roomID,
                            const std::string& date);
    bool cancelBooking(const std::string& bookingID);
    bool approveBooking(const std::string& bookingID);

    IRoom* getRoom(const std::string& roomID) const;
    std::vector<IRoom*> getAvailableRooms(const std::string& date, int requiredCapacity) const;
};
