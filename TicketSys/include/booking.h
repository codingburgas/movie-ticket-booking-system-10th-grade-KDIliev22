#ifndef BOOKING_H
#define BOOKING_H

#include <string>
#include "seat.h"
#include "show.h"

class Booking {
private:
    std::string customerName;
    Show show;
    Seat seat;
public:
    Booking(const std::string& customerName, const Show& show, const Seat& seat);
    std::string getCustomerName() const;
    Show getShow() const;
    Seat getSeat() const;
};

#endif
