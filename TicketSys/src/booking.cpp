#include "booking.h"

Booking::Booking(const std::string& customerName, const Show& show, const Seat& seat)
        : customerName(customerName), show(show), seat(seat) {}
std::string Booking::getCustomerName() const {
    return customerName;
}
Show Booking::getShow() const {
    return show;
}
Seat Booking::getSeat() const {
    return seat;
}
