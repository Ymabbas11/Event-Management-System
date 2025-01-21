#include "Faculty.h"

Faculty::Faculty(const std::string& id, const std::string& name, const std::string& email)
    : User(id, name, email) {
    role = "Faculty";
}

bool Faculty::login() {
    return true;
}

void Faculty::viewEvents() {
    // Implement view events logic
}

bool Faculty::registerForEvent(const std::string& eventID) {
    return true;
} 