#include "bookingsystem.h"
#include <iostream>

void BookingSystem::bookSeats(Show* show, std::string customerName, std::vector<std::string> seatNumbers) {
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

void BookingSystem::makeBooking(std::string customerName, std::string paymentMethod, std::string bookingType, Show* show) {
    std::cout << "Booking made for " << customerName << ". Payment form: " << paymentMethod << " (" << bookingType << ")\n";
}

void BookingSystem::listBookings() {
    std::cout << "Listing all bookings.\n";
}