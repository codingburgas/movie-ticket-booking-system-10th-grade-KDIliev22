#ifndef BOOKINGSYSTEM_H
#define BOOKINGSYSTEM_H

#include "booking.h"

class BookingSystem {
public:
    Booking* bookingHead;
    BookingSystem() : bookingHead(nullptr) {}
    void makeBooking(std::string customerName, std::string paymentMethod, std::string bookingType, Show* show) {
        if (bookingType == "online" && paymentMethod != "card") {
            std::cout << "Online bookings can only be paid by card.\n";
            return;
        }
        Booking* newBooking = new Booking(customerName, paymentMethod, bookingType, show);
        if (!bookingHead) bookingHead = newBooking;
        else {
            Booking* temp = bookingHead;
            while (temp->next) temp = temp->next;
            temp->next = newBooking;
        }
        std::cout << "Booking successful for " << customerName << " (" << bookingType << ", " << paymentMethod << ")\n";
    }
    void listBookings() {
        Booking* temp = bookingHead;
        while (temp) {
            std::cout << "Customer: " << temp->customerName << ", Show: " << temp->showBooked->movie->title << " at " << temp->showBooked->time << ", Payment: " << temp->paymentMethod << ", Type: " << temp->bookingType << "\n";
            temp = temp->next;
        }
    }
};


#endif //BOOKINGSYSTEM_H
