#ifndef SEAT_H
#define SEAT_H

#include <string>

class Seat {
public:
    std::string seatNumber;
    std::string seatType;
    double price;
    bool isBooked;
    Seat* next;
    Seat(std::string number, std::string type);
};

#endif