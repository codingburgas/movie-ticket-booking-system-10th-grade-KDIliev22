#include <iostream>
#include "precompiler.h"
int main() {
    bool running = true;
    while (running) {
        std::string customerName;
        int seatNumber;
        std::cout << "\n=== Buy a ticket ===\n";
        std::cout << "Enter your name: ";
        std::cin >> customerName;
        std::cout << "Choose seat number: ";
        std::cin >> seatNumber;
        Seat customSeat(seatNumber, "Silver");
        Show show("Back to the Future", "10:17 PM");
        Booking userBooking(customerName, show, customSeat);
        userBooking.saveToFile("../data/bookings.txt");
        std::cout << "Booking confirmed for " << userBooking.getCustomerName()
                  << " - Seat #" << userBooking.getSeat().getNumber() << "\n";
        std::cout << "Book another? (1: Yes, 0: No): ";
        std::cin >> running;
    }
    std::cout << "That's all folks!\n";
    return 0;
}
