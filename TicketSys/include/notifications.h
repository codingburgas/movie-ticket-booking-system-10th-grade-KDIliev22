#ifndef NOTIFICATIONS_H
#define NOTIFICATIONS_H

#include <string>
#include <vector>

class NotificationSystem {
public:
    static void addNotification(const std::string& message);
    static std::vector<std::string> getNotifications();
    static void clearNotifications();
};

#endif