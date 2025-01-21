#include "BookingManager.h"
#include <sstream>

// Constructor implementation
BookingManager::BookingManager() {}

// Destructor implementation
BookingManager::~BookingManager() {
    for (auto iter = rooms.begin(); iter != rooms.end(); ++iter) {
        delete iter->second;
    }
    rooms.clear();
}

void BookingManager::addRoom(const std::string& roomID, const std::string& building, int capacity) {
    try {
        IRoom* room = RoomFactory::createRoom(roomID, building, capacity);
        rooms[roomID] = room;
    } catch (const std::invalid_argument& e) {
        throw; // Re-throw the exception to be handled by the caller
    }
}

std::string BookingManager::createBooking(const std::string& eventID,
                                        const std::string& roomID,
                                        const std::string& date) {
    // Check if room exists
    auto roomIt = rooms.find(roomID);
    if (roomIt == rooms.end()) {
        return "";
    }

    // Check room availability
    if (!roomIt->second->checkAvailability(date)) {
        return "";
    }

    // Generate booking ID
    std::string bookingID = "BKG" + std::to_string(bookings.size() + 1);

    // Create and store booking
    Booking booking{
        bookingID,
        eventID,
        roomID,
        date,
        false  // Not approved by default
    };

    bookings[bookingID] = booking;

    // Reserve the room
    roomIt->second->reserve(date);

    return bookingID;
}

bool BookingManager::cancelBooking(const std::string& bookingID) {
    auto it = bookings.find(bookingID);
    if (it == bookings.end()) {
        return false;
    }

    // Release the room
    auto roomIt = rooms.find(it->second.roomID);
    if (roomIt != rooms.end()) {
        roomIt->second->release(it->second.date);
    }

    bookings.erase(it);
    return true;
}

bool BookingManager::approveBooking(const std::string& bookingID) {
    auto it = bookings.find(bookingID);
    if (it == bookings.end()) {
        return false;
    }

    it->second.isApproved = true;
    return true;
}

IRoom* BookingManager::getRoom(const std::string& roomID) const {
    auto it = rooms.find(roomID);
    if (it != rooms.end()) {
        return it->second;
    }
    return nullptr;
}

std::vector<IRoom*> BookingManager::getAvailableRooms(const std::string& date, int requiredCapacity) const {
    std::vector<IRoom*> availableRooms;
    for (const auto& pair : rooms) {
        IRoom* room = pair.second;
        if (room->getCapacity() >= requiredCapacity && room->checkAvailability(date)) {
            availableRooms.push_back(room);
        }
    }
    return availableRooms;
}
