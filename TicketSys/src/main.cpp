#include <iostream>
#include <fstream>
#include <filesystem>
#include "cinema.h"
#include "bookingsystem.h"
namespace fs = std::filesystem;
bool userExists(const std::string& username) {
    return fs::exists(username + "_account.txt");
}
void registerUser(const std::string& username) {
    std::ofstream outFile(username + "_account.txt");
    if (outFile.is_open()) {
        outFile << "Username: " << username << "\n";
        outFile.close();
        std::cout << "User registered successfully.\n";
    } else {
        std::cout << "Failed to register user.\n";
    }
}

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
    std::string username;
    int loginChoice;
    std::cout << "----- Welcome to Movie Ticket System -----\n";
    std::cout << "1. Login\n";
    std::cout << "2. Register\n";
    std::cout << "Enter choice: ";
    std::cin >> loginChoice;
    std::cin.ignore();
    if (loginChoice == 1) {
        std::cout << "Enter your username: ";
        getline(std::cin, username);
        if (!userExists(username)) {
            std::cout << "User not found. Exiting.\n";
            return 0;
        } else {
            std::cout << "Login successful.\n";
        }
    } else if (loginChoice == 2) {
        std::cout << "Enter desired username: ";
        getline(std::cin, username);
        if (userExists(username)) {
            std::cout << "User already exists. Exiting.\n";
            return 0;
        } else {
            registerUser(username);
        }
    } else {
        std::cout << "Invalid choice. Exiting.\n";
        return 0;
    }
    int choice;
    do {
        std::cout << "Movie ticket booking system --------- /\n";
        std::cout << "Logged in as: " << username << "\n";
        std::cout << "1. List movies\n";
        std::cout << "2. List shows\n";
        std::cout << "3. Make a booking\n";
        std::cout << "4. List my bookings\n";
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
                        std::cout << "Hall: " << h->hallName
                                  << ", Movie: " << s->movie->title
                                  << ", Time: " << s->time << "\n";
                        s = s->next;
                    }
                    h = h->next;
                }
                break;
            }
            case 3: {
                std::string bookingType, paymentMethod, hallName, showTime;
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
                    std::ofstream outFile(username + "_bookings.txt", std::ios::app);
                    if (outFile.is_open()) {
                        outFile << "Booking: " << selectedShow->movie->title << ", Time: " << selectedShow->time << ", Hall: " << hallName << ", Payment: " << paymentMethod << ", Type: " << bookingType << "\n";
                        outFile.close();
                        std::cout << "Booking saved for " << selectedShow->movie->title << " at " << selectedShow->time << ".\n";
                    } else {
                        std::cout << "Failed to save booking.\n";
                    }
                } else {
                    std::cout << "Show not found.\n";
                }
                break;
            }
            case 4: {
                std::cout << "--- My Bookings ---\n";
                std::ifstream inFile(username + "_bookings.txt");
                if (inFile.is_open()) {
                    std::string line;
                    while (getline(inFile, line)) {
                        std::cout << line << "\n";
                    }
                    inFile.close();
                } else {
                    std::cout << "No bookings found.\n";
                }
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
