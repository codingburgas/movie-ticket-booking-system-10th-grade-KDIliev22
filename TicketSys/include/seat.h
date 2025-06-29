#ifndef SEAT_H
#define SEAT_H

#include <string>

class Seat {
public:
    std::string seatNumber;
    std::string seatType;
    bool isBooked;
    Seat* next;
    Seat(std::string number, std::string type) : seatNumber(number), seatType(type), isBooked(false), next(nullptr) {}
};

#endif //SEAT_H