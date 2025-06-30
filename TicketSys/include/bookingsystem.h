#ifndef BOOKINGSYSTEM_H
#define BOOKINGSYSTEM_H

#include "show.h"
#include "notifications.h"
#include <vector>
#include <string>

class BookingSystem {
public:
    void bookSeats(Show* show, const std::string& customerName, const std::vector<std::string>& seatNumbers);
    void cancelBooking(Show* show, const std::string& customerName, const std::vector<std::string>& seatNumbers);
};

#endif