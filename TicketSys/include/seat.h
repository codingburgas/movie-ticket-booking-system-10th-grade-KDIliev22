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
    Seat(std::string number, std::string type) : seatNumber(number), seatType(type), isBooked(false), next(nullptr) {
        if (type == "front row") price = 10;
        else if (type == "back") price = 15;
        else if (type == "middle") price = 20;
        else price = 10.0;
    }
};

#endif // SEAT_H