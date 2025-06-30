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

bool isAdmin(const std::string& username) {
    return username == "admin";
}

void adminMenu(Cinema& cinema) {
    int choice;
    do {
        std::cout << "\n--- Admin Menu ---\n";
        std::cout << "1. Add Movie\n";
        std::cout << "2. Delete Movie\n";
        std::cout << "3. Add Show\n";
        std::cout << "4. Delete Show\n";
        std::cout << "0. Back to Main Menu\n";
        std::cout << "Enter choice: ";
        std::cin >> choice;
        std::cin.ignore();

        switch (choice) {
            case 1: {
                std::string title, language, genre, releaseDate;
                std::cout << "Enter movie title: ";
                getline(std::cin, title);
                std::cout << "Enter language: ";
                getline(std::cin, language);
                std::cout << "Enter genre: ";
                getline(std::cin, genre);
                std::cout << "Enter release date: ";
                getline(std::cin, releaseDate);
                cinema.addMovie(title, language, genre, releaseDate);
                std::cout << "Movie added successfully.\n";
                break;
            }
            case 2: {
                std::string title;
                std::cout << "Enter movie title to delete: ";
                getline(std::cin, title);
                cinema.deleteMovie(title);
                std::cout << "Movie deleted if it existed.\n";
                break;
            }
            case 3: {
                std::string hallName, time, movieTitle;
                std::cout << "Enter hall name: ";
                getline(std::cin, hallName);
                std::cout << "Enter show time: ";
                getline(std::cin, time);
                std::cout << "Enter movie title: ";
                getline(std::cin, movieTitle);

                Movie* movie = cinema.movieHead;
                while (movie && movie->title != movieTitle) {
                    movie = movie->next;
                }

                if (!movie) {
                    std::cout << "Movie not found.\n";
                    break;
                }

                Hall* hall = cinema.hallHead;
                while (hall && hall->hallName != hallName) {
                    hall = hall->next;
                }

                if (!hall) {
                    std::cout << "Hall not found.\n";
                    break;
                }

                hall->addShow(time, movie);
                std::cout << "Show added successfully.\n";
                break;
            }
            case 4: {
                std::string hallName, time;
                std::cout << "Enter hall name: ";
                getline(std::cin, hallName);
                std::cout << "Enter show time: ";
                getline(std::cin, time);
                cinema.deleteShow(hallName, time);
                std::cout << "Show deleted if it existed.\n";
                break;
            }
        }
    } while (choice != 0);
}
void displaySeats(Show* show) {
    std::cout << "\n--- Available Seats ---\n";
    Seat* seat = show->seatHead;
    while (seat) {
        std::cout << "Seat " << seat->seatNumber << " (" << seat->seatType << ") - $" << seat->price << " - " << (seat->isBooked ? "Booked" : "Available") << "\n";
        seat = seat->next;
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

    Show* show1 = hallA->showHead;
    Show* show2 = hallB->showHead;

    for (int i = 1; i <= 10; i++) {
        std::string type = "front row";
        if (i > 7) type = "middle";
        else if (i > 3) type = "back";

        show1->addSeat(std::to_string(i), type);
        show2->addSeat(std::to_string(i), type);
    }
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
        if (isAdmin(username)) {
            std::cout << "ADMIN MODE\n";
            adminMenu(cinema);
            continue;
        }
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
                        std::cout << "Hall: " << h->hallName << ", Movie: " << s->movie->title << ", Time: " << s->time << "\n";
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
                if (bookingType == "online") {
                    paymentMethod = "card";
                } else {
                    std::cout << "Enter payment method (card/cash): ";
                    getline(std::cin, paymentMethod);
                }
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
                    displaySeats(selectedShow);
                    std::vector<std::string> selectedSeats;
                    std::string seatNumber;
                    double total = 0.0;
                    std::cout << "Enter seat numbers to book (one per line, empty to finish):\n";
                    while (true) {
                        getline(std::cin, seatNumber);
                        if (seatNumber.empty()) break;
                        Seat* seat = selectedShow->findSeat(seatNumber);
                        if (!seat) {
                            std::cout << "Invalid seat number.\n";
                            continue;
                        }
                        if (seat->isBooked) {
                            std::cout << "Seat " << seatNumber << " is already booked.\n";
                            continue;
                        }
                        selectedSeats.push_back(seatNumber);
                        total += seat->price;
                        std::cout << "Added seat " << seatNumber << " ($" << seat->price << ")\n";
                    }
                    if (!selectedSeats.empty()) {
                        BookingSystem bs;
                        bs.bookSeats(selectedShow, username, selectedSeats);
                        std::ofstream outFile(username + "_bookings.txt", std::ios::app);
                        if (outFile.is_open()) {
                            outFile << "Booking: " << selectedShow->movie->title << ", Time: " << selectedShow->time << ", Hall: " << hallName << ", Seats: ";
                            for (const auto& seat : selectedSeats) {
                                outFile << seat << " ";
                            }
                            outFile << ", Total: $" << total << ", Payment: " << paymentMethod << ", Type: " << bookingType << "\n";
                            outFile.close();
                            std::cout << "Booking saved!\n";
                        } else {
                            std::cout << "Failed to save booking.\n";
                        }
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
    } while (choice != 0);
    return 0;
}