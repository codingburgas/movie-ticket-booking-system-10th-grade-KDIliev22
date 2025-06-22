#ifndef SEAT_H
#define SEAT_H

#include <string>

class Seat {
private:
    int number;
    std::string type;
    bool booked;
public:
    Seat();
    Seat(int number, const std::string& type);
    int getNumber() const;
    std::string getType() const;
    bool isBooked() const;
    void book();
};

#endif
