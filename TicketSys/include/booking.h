#ifndef BOOKING_H
#define BOOKING_H

#include <string>
#include "show.h"

class Booking {
public:
    std::string customerName;
    std::string paymentMethod;
    std::string bookingType;
    Show* showBooked;
    Booking* next;
    Booking(std::string name, std::string payment, std::string type, Show* show);
};

#endif