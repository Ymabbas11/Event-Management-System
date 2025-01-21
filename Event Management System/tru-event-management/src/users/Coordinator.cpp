#include "Coordinator.h"
#include "EventManager.h"
#include "Event.h"

Coordinator::Coordinator(const std::string& id, const std::string& name, const std::string& email)
    : User(id, name, email) {
    role = "Coordinator";
}

bool Coordinator::login() {
    return true;
}

void Coordinator::viewEvents() {
    // Implementation for viewing the events
}

bool Coordinator::registerForEvent(const std::string& eventID) {
    return true;
}

bool Coordinator::approveEvent(const std::string& eventID, EventManager* eventManager) {
    if (!eventManager) return false;

    Event* event = eventManager->getEvent(eventID);
    if (!event) {
        return false;
    }

    return event->setApproved(true);
}
