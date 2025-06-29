#ifndef BOOKINGSYSTEM_H
#define BOOKINGSYSTEM_H

#include <iostream>
#include <vector>
#include "show.h"

class BookingSystem {
public:
    void bookSeats(Show* show, std::string customerName, std::vector<std::string> seatNumbers) {
        for (std::string number : seatNumbers) {
            Seat* seat = show->findSeat(number);
            if (seat) {
                if (!seat->isBooked) {
                    seat->isBooked = true;
                    std::cout << "Seat " << seat->seatNumber << " booked for " << customerName << " (" << seat->seatType << ")\n";
                } else {
                    std::cout << "Seat " << seat->seatNumber << " is already booked.\n";
                }
            } else {
                std::cout << "Seat " << number << " does not exist.\n";
            }
        }
    }
};

#endif // BOOKINGSYSTEM_H
