#ifndef BOOKINGSYSTEM_H
#define BOOKINGSYSTEM_H

#include <vector>
#include "show.h"

class BookingSystem {
public:
    void bookSeats(Show* show, std::string customerName, std::vector<std::string> seatNumbers);
    void makeBooking(std::string customerName, std::string paymentMethod, std::string bookingType, Show* show);
    void listBookings();
};

#endif