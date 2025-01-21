# Event Management System

## Project Overview
The **Event Management System** is a platform designed to simplify the scheduling, management, and participation in events for universities and similar organizations. Unlike generic solutions such as Google Calendar or basic room booking systems, this project is tailored for multi-role interaction among faculty, students, and coordinators, leveraging Object-Oriented Design (OOD) principles.

---

## Features

### Core Functionalities
- **Event Creation and Approval**:
  - Faculty can create events, which must be approved by coordinators.
  - Real-time validation prevents scheduling conflicts.
- **Room Booking and Management**:
  - Book rooms dynamically with conflict checks.
  - Manage room availability efficiently.
- **Event Participation**:
  - Students can register for events and join waitlists.
  - FIFO-based queue management ensures fair waitlist handling.

---

## System Design

### Class Structure
- **User Hierarchy**:
  - Base class: `User`
  - Derived classes: `Student`, `Faculty`, `Coordinator`
- **Event and Room Management**:
  - Classes: `Event`, `EventManager`, `Room`, `ConferenceRoom`
  - `BookingManager` handles room reservations.
- **Relationships**:
  - Inheritance: Specialized users (Student, Faculty, Coordinator) inherit from `User`.
  - Composition: `EventManager` contains `Event` objects.
  - Dependency: `BookingManager` interacts with `RoomFactory` for room creation.

### Data Structures
- **Maps**: Efficiently store event and room booking details.
- **Vectors**: Maintain participant lists for events.
- **Queues**: Manage waitlists using FIFO principles.

### Key Algorithms and Highlights
- **Conflict Resolution**:
  - Prevents overlapping events using the `hasScheduleConflict` method in `EventManager`.
- **Dynamic Room Assignment**:
  - Utilizes `checkAvailability` and `getAvailableRooms` functions to assign rooms without conflicts.
- **Validation**:
  - `isValidDate` ensures correct date format (YYYY-MM-DD).
  - `isValidEmail` validates email formats.
- **Error Handling**:
  - Exception handling ensures robust conflict management during bookings.
- **Modular Design**:
  - High cohesion and low coupling between modules ensure maintainability.

---

## Installation and Setup

1. Clone the repository:
   ```bash
   git clone https://github.com/yourusername/EventManagementSystem.git
   cd EventManagementSystem
   ```

2. Compile the project (C++):
   ```bash
   g++ -std=c++17 -o EventManagementSystem main.cpp BookingManager.cpp EventManager.cpp Utils.cpp Room.cpp ConferenceRoom.cpp Student.cpp Faculty.cpp Coordinator.cpp User.cpp
   ```

3. Run the program:
   ```bash
   ./EventManagementSystem
   ```

---

## Future Improvements
- **Database Integration**:
  - Replace temporary memory with persistent storage for long-term data retention.
- **User Interface**:
  - Develop a graphical user interface (GUI) for better usability.
- **Real-Time Notifications**:
  - Implement smart notifications for event updates and booking confirmations.
- **Scalability**:
  - Optimize for high-concurrency environments and smart room filtering.

---

## Contributing
Contributions are welcome! If you have ideas for new features or improvements, please create an issue or submit a pull request.

---

## Authors
- **Pui Hei Wong** - User & Room Management
- **Mohammed Sadiq** - Designer/Tester
- **Mohammed Abbas** - Event Handling

---

## License
This project is licensed under the MIT License. See the `LICENSE` file for details.

---

## Acknowledgments
Special thanks to the COMP 3140 course team for their guidance and support.
