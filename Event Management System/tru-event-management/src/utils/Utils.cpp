#include "Utils.h"
#include <iostream>
#include <algorithm>
#include <cctype>
#include <limits>

std::string toUpper(std::string str) {
    std::transform(str.begin(), str.end(), str.begin(), ::toupper);
    return str;
}

std::string toProperCase(std::string str) {
    if (str.empty()) return str;
    str[0] = std::toupper(str[0]);
    for (size_t i = 1; i < str.length(); ++i) {
        str[i] = std::tolower(str[i]);
    }
    return str;
}

void clearInputBuffer() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void printEventDetails(const Event* event) {
    std::cout << "\nEvent Details:" << std::endl;
    std::cout << "Event ID: " << event->getEventID() << std::endl;
    std::cout << "Name: " << event->getName() << std::endl;
    std::cout << "Date: " << event->getDate() << std::endl;
    std::cout << "Time: " << event->getTime() << std::endl;
    std::cout << "Location: " << event->getLocation() << std::endl;
    std::cout << "Current Participants: " << event->getCurrentCapacity()
              << "/" << event->getMaxCapacity() 
              << " (Waitlist: " << event->getWaitlistSize() << ")" << std::endl;
    std::cout << "Approval Status: " << (event->getApproved() ? "Approved" : "Pending") << std::endl;
    std::cout << "----------------------------------------\n";
}

std::string getUserInput(const std::string& prompt, bool makeUpper, bool properCase) {
    std::string input;
    std::cout << prompt;
    std::getline(std::cin, input);
    if (makeUpper) return toUpper(input);
    if (properCase) return toProperCase(input);
    return input;
}

bool isValidDate(const std::string& date) {
    if (date.length() != 10) return false;
    if (date[4] != '-' || date[7] != '-') return false;
    for (int i = 0; i < 10; i++) {
        if (i != 4 && i != 7 && !std::isdigit(date[i])) return false;
    }
    return true;
}

bool isValidEmail(const std::string& email) {
    return email.find('@') != std::string::npos && email.find('.') != std::string::npos;
}

int getIntInput(const std::string& prompt) {
    int input;
    while (true) {
        std::cout << prompt;
        if (std::cin >> input && input > 0) {
            clearInputBuffer();
            return input;
        }
        std::cout << "Invalid input. Please enter a positive number.\n";
        clearInputBuffer();
    }

}

bool isValidTime(const std::string& time) {
    if (time.length() != 5) return false;
    if (time[2] != ':') return false;
    
    for (int i = 0; i < 5; i++) {
        if (i != 2 && !std::isdigit(time[i])) return false;
    }
    
    int hours = std::stoi(time.substr(0, 2));
    int minutes = std::stoi(time.substr(3, 2));
    
    return hours >= 0 && hours < 24 && minutes >= 0 && minutes < 60;
}
