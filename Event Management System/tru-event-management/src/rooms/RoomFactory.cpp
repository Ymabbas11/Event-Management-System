#include "RoomFactory.h"
#include "Room.h"

// Define the static member variables
const std::vector<std::string> RoomFactory::validOMRooms = {"OM1234", "OM1235", "OM2301"};
const std::vector<std::string> RoomFactory::validHLRooms = {"HL101", "HL102", "HL201", "HL202"};

IRoom* RoomFactory::createRoom(const std::string& roomID, const std::string& building, int capacity) {
    if (!isValidRoomID(roomID)) {
        throw std::invalid_argument("Invalid room ID. Valid OM rooms are: OM1234, OM1235, OM2301");
    }

    if (capacity <= 0) {
        throw std::invalid_argument("Capacity must be greater than 0");
    }

    return new Room(roomID, building, capacity);
}

bool RoomFactory::isValidRoomID(const std::string& roomID) {
    return isValidOMRoom(roomID) || isValidHLRoom(roomID);
}

bool RoomFactory::isValidOMRoom(const std::string& roomID) {
    return std::find(validOMRooms.begin(), validOMRooms.end(), roomID) != validOMRooms.end();
}

bool RoomFactory::isValidHLRoom(const std::string& roomID) {
    return std::find(validHLRooms.begin(), validHLRooms.end(), roomID) != validHLRooms.end();
} 