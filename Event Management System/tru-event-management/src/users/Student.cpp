#include "Student.h"

Student::Student(const std::string& id, const std::string& name, const std::string& email)
    : User(id, name, email) {
    role = "Student";
}

bool Student::login() {
    // Implement login logic
    return true;
}

void Student::viewEvents() {
    // Implement view events logic
}

bool Student::registerForEvent(const std::string& eventID) {
    // Implement registration logic
    return true;
} 