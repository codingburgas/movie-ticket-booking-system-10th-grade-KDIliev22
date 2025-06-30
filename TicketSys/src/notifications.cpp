#include "notifications.h"
#include <fstream>
#include <iomanip>

void NotificationSystem::addNotification(const std::string& message) {
    std::ofstream file("notifications.txt", std::ios::app);
    if (file.is_open()) {
        file << message << "\n";
    }
}

std::vector<std::string> NotificationSystem::getNotifications() {
    std::vector<std::string> notifications;
    std::ifstream file("notifications.txt");
    std::string line;
    while (getline(file, line)) {
        notifications.push_back(line);
    }
    return notifications;
}

void NotificationSystem::clearNotifications() {
    remove("notifications.txt");
}