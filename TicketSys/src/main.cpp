#include <iostream>
#include "cinema.h"
#include "bookingsystem.h"

int main() {
    Cinema cinema("Cinema City");
    BookingSystem bookingSystem;
    cinema.addMovie("Kill Bill", "English", "Thriller", "2003");
    cinema.addMovie("The Grand Budapest Hotel", "English", "Comedy", "2014");
    cinema.addHall("Hall A");
    cinema.addHall("Hall B");
    Hall* hallA = cinema.hallHead;
    Hall* hallB = hallA->next;
    hallA->addShow("18:00", cinema.movieHead);
    hallB->addShow("20:00", cinema.movieHead->next);
    int choice;
    do {
        std::cout << "Movie ticket booking system --------- /\n";
        std::cout << "1. List movies\n";
        std::cout << "2. List shows\n";
        std::cout << "3. Make a booking\n";
        std::cout << "4. List bookings\n";
        std::cout << "0. Exit\n";
        std::cout << "Enter choice: ";
        std::cin >> choice;
        std::cin.ignore();

        switch (choice) {
            case 1: {
                std::cout << "--- Movies ---\n";
                Movie* m = cinema.movieHead;
                while (m) {
                    std::cout << m->title << " (" << m->genre << ", " << m->language << ", " << m->releaseDate << ")\n";
                    m = m->next;
                }
                break;
            }
            case 2: {
                std::cout << "--- Shows ---\n";
                Hall* h = cinema.hallHead;
                while (h) {
                    Show* s = h->showHead;
                    while (s) {
                        std::cout << "Hall: " << h->hallName << ", Movie: " << s->movie->title << ", Time: " << s->time << "\n";
                        s = s->next;
                    }
                    h = h->next;
                }
                break;
            }
            case 3: {
                std::string customerName, paymentMethod, bookingType;
                std::string hallName, showTime;
                std::cout << "Enter customer name: ";
                getline(std::cin, customerName);
                std::cout << "Enter booking type (online/walk-in): ";
                getline(std::cin, bookingType);
                std::cout << "Enter payment method (card/cash): ";
                getline(std::cin, paymentMethod);
                std::cout << "Enter hall name: ";
                getline(std::cin, hallName);
                std::cout << "Enter show time: ";
                getline(std::cin, showTime);
                Hall* selectedHall = cinema.hallHead;
                Show* selectedShow = nullptr;
                while (selectedHall) {
                    if (selectedHall->hallName == hallName) {
                        Show* s = selectedHall->showHead;
                        while (s) {
                            if (s->time == showTime) {
                                selectedShow = s;
                                break;
                            }
                            s = s->next;
                        }
                        break;
                    }
                    selectedHall = selectedHall->next;
                }
                if (selectedShow) {
                    //bookingSystem.makeBooking(customerName, paymentMethod, bookingType, selectedShow);
                } else {
                    std::cout << "Show not found.\n";
                }

                break;
            }
            case 4: {
                std::cout << "--- All Bookings ---\n";
                //bookingSystem.listBookings();
                break;
            }
            case 0:
                std::cout << "Exiting system.\n";
                break;
            default:
                std::cout << "Invalid choice.\n";
        }
        std::cout << "\n";
    } while (choice != 0);
    return 0;
}