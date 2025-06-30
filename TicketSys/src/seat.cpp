#include "seat.h"

Seat::Seat(std::string number, std::string type) : 
    seatNumber(number), seatType(type), isBooked(false), next(nullptr) {
    if (type == "front row") price = 10.0;
    else if (type == "back") price = 15.0;
    else if (type == "middle") price = 20.0;
    else price = 10.0;
}