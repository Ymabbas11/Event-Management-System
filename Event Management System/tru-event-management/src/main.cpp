#include <iostream>
#include "Utils.h"
#include "EventManager.h"
#include "BookingManager.h"
#include "Student.h"
#include "Faculty.h"
#include "Coordinator.h"

int main() {
    BookingManager* bookingManager = new BookingManager();
    EventManager* eventManager = new EventManager(bookingManager);

    try {
        // Add the Om rooms
        bookingManager->addRoom("OM1234", "Old Main Building", 50);
        bookingManager->addRoom("OM1235", "Old Main Building", 30);
        bookingManager->addRoom("OM2301", "Old Main Building", 40);

        // Add some HL rooms
        bookingManager->addRoom("HL101", "Holmes Building", 25);
        bookingManager->addRoom("HL102", "Holmes Building", 30);

    } catch (const std::invalid_argument& e) {
        std::cerr << "Error creating room: " << e.what() << std::endl;
        return 1;
    }

        while (true) {
            std::cout << "\n=== TRU Event Management System ===\n";
            std::cout << "1. Create new event (Faculty)\n";
            std::cout << "2. Register for event (Student)\n";
            std::cout << "3. View all events\n";
            std::cout << "4. Approve event room booking (Coordinator)\n";
            std::cout << "5. Exit\n";
            std::cout << "Choose an option: ";

        int choice;
        std::cin >> choice;
        std::cin.ignore();

            switch (choice) {
                case 1: {
                    std::cout << "\n=== Creating New Event ===\n";

                    // Get faculty details with validation
                    std::string facultyId = toUpper(getUserInput("Enter faculty ID (e.g., F101): "));
                    while (facultyId.empty() || facultyId[0] != 'F') {
                        std::cout << "Invalid ID format. ID must start with 'F'.\n";
                        facultyId = toUpper(getUserInput("Enter faculty ID (e.g., F101): "));
                    }

                    std::string facultyName = getUserInput("Enter faculty name: ", false, true);

                    std::string facultyEmail = getUserInput("Enter faculty email: ");
                    while (!isValidEmail(facultyEmail)) {
                        std::cout << "Invalid email format.\n";
                        facultyEmail = getUserInput("Enter faculty email: ");
                    }

                    Faculty* faculty = new Faculty(facultyId, facultyName, facultyEmail);

                    // Get event details with validation
                    std::string eventName = getUserInput("Enter event name: ", false, true);

                    std::string eventDate = getUserInput("Enter event date (YYYY-MM-DD): ");
                    while (!isValidDate(eventDate)) {
                        std::cout << "Invalid date format. Use YYYY-MM-DD.\n";
                        eventDate = getUserInput("Enter event date (YYYY-MM-DD): ");
                    }

                    std::string eventTime = getUserInput("Enter event time (HH:MM in 24-hour format): ");
                    while (!isValidTime(eventTime)) {
                        std::cout << "Invalid time format. Use HH:MM (24-hour format).\n";
                        eventTime = getUserInput("Enter event time (HH:MM in 24-hour format): ");
                    }

                    // First ask for building
                    std::cout << "Enter building (OM/HOL): ";
                    std::string building;
                    std::getline(std::cin, building);
                    building = toUpper(building);

                    while (building != "OM" && building != "HOL") {
                        std::cout << "Invalid building. Please enter either 'OM' or 'HOL'\n";
                        std::cout << "Enter building (OM/HOL): ";
                        std::getline(std::cin, building);
                        building = toUpper(building);
                    }

                    // Then ask for room number based on building
                    std::string roomNumber;
                    if (building == "OM") {
                        std::cout << "Enter room number (1xxx-3xxx): ";
                        std::getline(std::cin, roomNumber);
                        while (roomNumber.length() != 4 ||
                               !std::all_of(roomNumber.begin(), roomNumber.end(), ::isdigit) ||
                               std::stoi(roomNumber) < 1000 ||
                               std::stoi(roomNumber) > 3999) {
                            std::cout << "Invalid room number. Must be between 1xxx-3xxx.\n";
                            std::cout << "Enter room number (1xxx-3xxx): ";
                            std::getline(std::cin, roomNumber);
                        }
                    } else {  // HOL
                        std::cout << "Enter room number (1xx-4xx): ";
                        std::getline(std::cin, roomNumber);
                        while (roomNumber.length() != 3 ||
                               !std::all_of(roomNumber.begin(), roomNumber.end(), ::isdigit) ||
                               std::stoi(roomNumber) < 100 ||
                               std::stoi(roomNumber) > 499) {
                            std::cout << "Invalid room number. Must be between 1xx-4xx.\n";
                            std::cout << "Enter room number (1xx-4xx): ";
                            std::getline(std::cin, roomNumber);
                        }
                    }

                    // Construct the full room ID
                    std::string roomId = building + roomNumber;

                    int capacity = getIntInput("Enter maximum capacity: ");

                    try {
                        std::string eventId = eventManager->scheduleEvent(
                            eventName, eventDate, eventTime, roomId, capacity, faculty->getUserID()
                        );
                        std::cout << "\nEvent created successfully! Event ID: " << eventId << std::endl;
                        Event* event = eventManager->getEvent(eventId);
                        if (event) {
                            printEventDetails(event);
                        }
                    } catch (const std::runtime_error& e) {
                        std::cout << "Error creating event: " << e.what() << std::endl;
                    }
                    delete faculty;
                    break;
                }

                case 2: { // Register for event (Student)
                    std::cout << "\n=== Register for Event ===\n";

                    // Display all approved events
                    std::vector<Event*> approvedEvents = eventManager->getApprovedEvents();
                    if (approvedEvents.empty()) {
                        std::cout << "No events are currently available for registration.\n";
                        break;
                    }

                    std::cout << "Available Events for Registration:\n";
                    for (const auto& event : approvedEvents) {
                        printEventDetails(event);
                    }

                    std::string studentId = toUpper(getUserInput("Enter student ID: "));
                    std::string studentName = getUserInput("Enter student name: ", false, true);
                    std::string studentEmail = getUserInput("Enter student email: ");
                    while (!isValidEmail(studentEmail)) {
                        std::cout << "Invalid email format.\n";
                        studentEmail = getUserInput("Enter student email: ");
                    }

                    std::string eventId = toUpper(getUserInput("Enter event ID to register (e.g., EVT1): "));

                    Event* event = eventManager->getEvent(eventId);
                    if (!event) {
                        std::cout << "Event not found!\n";
                        break;
                    }

                    if (!event->getApproved()) {
                        std::cout << "Event is pending approval by the coordinator. Please try again later.\n";
                        break;
                    }

                if (event->addParticipant(studentId)) {
                    std::cout << "Registration successful!\n";
                } else if (event->isFull()) {
                    std::cout << "Event is full. Adding to waitlist...\n";
                    if (event->addToWaitlist(studentId)) {
                        std::cout << "Added to waitlist successfully!\n";
                    }
                } else {
                    std::cout << "Failed to register for the event.\n";
                }
                break;
            }

            case 3: { // View all events
                std::cout << "\n=== All Events ===\n";
                std::vector<Event*> allEvents = eventManager->getAllEvents(); // Assuming you have a method to get all events
                for (const auto& event : allEvents) {
                    printEventDetails(event);
                }
                break;
            }

            case 4: {
                std::string eventID, facultyName;

                std::cout << "Enter Event ID to approve: ";
                std::getline(std::cin, eventID);

                std::cout << "Enter Faculty Name: ";
                std::getline(std::cin, facultyName);

                try {
                    Event* event = eventManager->getEvent(eventID);
                    if (!event) {
                        std::cout << "Event not found.\n";
                        break;
                    }

                    if (event->setApproved(true)) {
                        std::cout << "Event " << eventID << " has been approved by " << facultyName << ".\n";
                    } else {
                        std::cout << "Failed to approve event.\n";
                    }
                }
                catch (const std::exception& e) {
                    std::cout << "Error during approval: " << e.what() << "\n";
                }
                break;
            }

            case 5: {
                std::cout << "Exiting program...\n";
                delete eventManager;
                delete bookingManager;
                return 0;
            }

            default:
                std::cout << "Invalid option. Please try again.\n";
        }
    }

    delete eventManager;
    delete bookingManager;
    return 0;
}
