#pragma once
#include "IRoom.h"
#include <string>
#include <vector>
#include <regex>
#include <stdexcept>

class RoomFactory {
public:
    static IRoom* createRoom(const std::string& roomID, const std::string& building, int capacity);

private:
    static bool isValidRoomID(const std::string& roomID);
    static bool isValidOMRoom(const std::string& roomID);
    static bool isValidHLRoom(const std::string& roomID);
    
    // Store valid room numbers
    static const std::vector<std::string> validOMRooms;
    static const std::vector<std::string> validHLRooms;
}; 