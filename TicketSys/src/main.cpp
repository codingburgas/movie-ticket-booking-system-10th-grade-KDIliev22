#include <iostream>
#include <fstream>
#include <filesystem>
#include <vector>
#include "cinema.h"
#include "bookingsystem.h"
#include "datastorage.h"
#include "notifications.h"

namespace fs = std::filesystem;

bool userExists(const std::string& username) {
    return fs::exists(username + "_account.txt");
}

void registerUser(const std::string& username, bool isAdmin = false) {
    std::ofstream outFile(username + "_account.txt");
    if (outFile.is_open()) {
        outFile << "Username: " << username << "\n";
        outFile << "Admin: " << (isAdmin ? "yes" : "no") << "\n";
        outFile.close();
        std::cout << "User registered successfully.\n";
    } else {
        std::cout << "Failed to register user.\n";
    }
}

bool isAdmin(const std::string& username) {
    std::ifstream inFile(username + "_account.txt");
    if (inFile.is_open()) {
        std::string line;
        while (getline(inFile, line)) {
            if (line.find("Admin: yes") != std::string::npos) {
                return true;
            }
        }
    }
    return false;
}

void displaySeats(Show* show) {
    std::cout << "\n--- Available Seats ---\n";
    Seat* seat = show->seatHead;
    while (seat) {
        std::cout << seat->seatNumber << " (" << seat->seatType << ") - $" << seat->price << " - " << (seat->isBooked ? "Booked" : "Available") << "\n";
        seat = seat->next;
    }
}

void adminMenu(Cinema& cinema) {
    int choice;
    do {
        std::cout << "\n=== ADMIN MENU ===\n";
        std::cout << "1. Add Movie\n";
        std::cout << "2. Add Hall\n";
        std::cout << "3. Add Show\n";
        std::cout << "4. View Movies\n";
        std::cout << "5. View Halls\n";
        std::cout << "6. View Shows\n";
        std::cout << "7. View Notifications\n";
        std::cout << "8. Save All Data\n";
        std::cout << "0. Back to Main Menu\n";
        std::cout << "Choice: ";
        std::cin >> choice;
        std::cin.ignore();

        switch (choice) {
            case 1: {
                std::string title, language, genre, releaseDate;
                std::cout << "Movie Title: ";
                getline(std::cin, title);
                std::cout << "Language: ";
                getline(std::cin, language);
                std::cout << "Genre: ";
                getline(std::cin, genre);
                std::cout << "Release Date: ";
                getline(std::cin, releaseDate);
                cinema.addMovie(title, language, genre, releaseDate);
                std::cout << "Movie added successfully.\n";
                break;
            }
            case 2: {
                std::string hallName;
                std::cout << "Hall Name: ";
                getline(std::cin, hallName);
                cinema.addHall(hallName);
                std::cout << "Hall added successfully.\n";
                break;
            }
            case 3: {
                std::string hallName, time, movieTitle;
                std::cout << "Hall Name: ";
                getline(std::cin, hallName);
                std::cout << "Show Time: ";
                getline(std::cin, time);
                std::cout << "Movie Title: ";
                getline(std::cin, movieTitle);

                Movie* movie = cinema.movieHead;
                while (movie && movie->title != movieTitle) movie = movie->next;

                Hall* hall = cinema.hallHead;
                while (hall && hall->hallName != hallName) hall = hall->next;

                if (hall && movie) {
                    hall->addShow(time, movie);
                    std::cout << "Show added successfully.\n";
                } else {
                    std::cout << "Error: Hall or Movie not found.\n";
                }
                break;
            }
            case 4: {
                std::cout << "\n--- Movies ---\n";
                Movie* m = cinema.movieHead;
                while (m) {
                    std::cout << m->title << " (" << m->language << ", " << m->genre << ", " << m->releaseDate << ")\n";
                    m = m->next;
                }
                break;
            }
            case 5: {
                std::cout << "\n--- Halls ---\n";
                Hall* h = cinema.hallHead;
                while (h) {
                    std::cout << h->hallName << "\n";
                    h = h->next;
                }
                break;
            }
            case 6: {
                std::cout << "\n--- Shows ---\n";
                Hall* h = cinema.hallHead;
                while (h) {
                    Show* s = h->showHead;
                    while (s) {
                        std::cout << h->hallName << ": " << s->movie->title << " at " << s->time << "\n";
                        s = s->next;
                    }
                    h = h->next;
                }
                break;
            }
            case 7: {
                std::cout << "\n=== NOTIFICATIONS ===\n";
                auto notes = NotificationSystem::getNotifications();
                if (notes.empty()) {
                    std::cout << "No notifications\n";
                } else {
                    for (const auto& note : notes) {
                        std::cout << note << "\n";
                    }
                }
                break;
            }
            case 8: {
                DataStorage::saveMovies(cinema.movieHead);
                DataStorage::saveHalls(cinema.hallHead);
                DataStorage::saveShows(cinema.hallHead);
                std::cout << "All data saved successfully!\n";
                break;
            }
        }
    } while (choice != 0);
}

int main() {
    if (!fs::exists("admin_account.txt")) {
        registerUser("admin", true);
    }
    Cinema cinema("Cinema City");
    cinema.movieHead = DataStorage::loadMovies();
    cinema.hallHead = DataStorage::loadHalls();
    DataStorage::loadShows(cinema.hallHead, cinema.movieHead);
    Hall* hall = cinema.hallHead;
    while (hall) {
        Show* show = hall->showHead;
        while (show) {
            for (int i = 1; i <= 10; i++) {
                std::string type = "silver";
                if (i > 7) type = "platinum";
                else if (i > 3) type = "gold";
                show->addSeat(std::to_string(i), type);
            }
            show = show->next;
        }
        hall = hall->next;
    }

    std::string username;
    int loginChoice;
    std::cout << "===== MOVIE TICKET SYSTEM =====\n";
    std::cout << "1. Login\n";
    std::cout << "2. Register\n";
    std::cout << "Choice: ";
    std::cin >> loginChoice;
    std::cin.ignore();

    if (loginChoice == 1) {
        std::cout << "Username: ";
        getline(std::cin, username);
        if (!userExists(username)) {
            std::cout << "User not found.\n";
            return 0;
        }
    } else if (loginChoice == 2) {
        std::cout << "Username: ";
        getline(std::cin, username);
        if (userExists(username)) {
            std::cout << "User already exists.\n";
            return 0;
        }
        registerUser(username);
    } else {
        return 0;
    }

    int choice;
    do {
        std::cout << "\n===== MAIN MENU =====\n";
        std::cout << "Logged in as: " << username << "\n";
        if (isAdmin(username)) {
            adminMenu(cinema);
            continue;
        }

        std::cout << "1. View Movies\n";
        std::cout << "2. View Shows\n";
        std::cout << "3. Book Tickets\n";
        std::cout << "4. Cancel Booking\n";
        std::cout << "5. View My Bookings\n";
        std::cout << "0. Exit\n";
        std::cout << "Choice: ";
        std::cin >> choice;
        std::cin.ignore();

        switch (choice) {
            case 1: {
                std::cout << "\n--- Movies ---\n";
                Movie* m = cinema.movieHead;
                while (m) {
                    std::cout << m->title << " (" << m->genre << ")\n";
                    m = m->next;
                }
                break;
            }
            case 2: {
                std::cout << "\n--- Shows ---\n";
                Hall* h = cinema.hallHead;
                while (h) {
                    Show* s = h->showHead;
                    while (s) {
                        std::cout << h->hallName << ": " << s->movie->title << " at " << s->time << "\n";
                        s = s->next;
                    }
                    h = h->next;
                }
                break;
            }
            case 3: {
                std::string hallName, showTime;
                std::cout << "Hall Name: ";
                getline(std::cin, hallName);
                std::cout << "Show Time: ";
                getline(std::cin, showTime);

                Hall* hall = cinema.hallHead;
                Show* show = nullptr;
                while (hall && !show) {
                    if (hall->hallName == hallName) {
                        Show* s = hall->showHead;
                        while (s && !show) {
                            if (s->time == showTime) {
                                show = s;
                            }
                            s = s->next;
                        }
                    }
                    hall = hall->next;
                }

                if (show) {
                    displaySeats(show);
                    std::vector<std::string> seats;
                    std::string seatNum;
                    double total = 0.0;

                    while (true) {
                        std::cout << "Seat Number (empty to finish): ";
                        getline(std::cin, seatNum);
                        if (seatNum.empty()) break;

                        Seat* seat = show->findSeat(seatNum);
                        if (!seat) {
                            std::cout << "Invalid seat number\n";
                            continue;
                        }

                        if (seat->isBooked) {
                            std::cout << "Seat already booked\n";
                            continue;
                        }

                        seats.push_back(seatNum);
                        total += seat->price;
                        std::cout << "Added seat " << seatNum << " ($" << seat->price << ")\n";
                    }

                    if (!seats.empty()) {
                        BookingSystem bs;
                        bs.bookSeats(show, username, seats);

                        std::ofstream outFile(username + "_bookings.txt", std::ios::app);
                        if (outFile.is_open()) {
                            outFile << show->movie->title << " at " << show->time << " in " << hallName << " - Seats: ";
                            for (const auto& s : seats) {
                                outFile << s << " ";
                            }
                            outFile << "- Total: $" << total << "\n";
                            outFile.close();
                        }
                        std::cout << "Booking successful!\n";
                    }
                } else {
                    std::cout << "Show not found\n";
                }
                break;
            }
            case 4: {
                std::string hallName, showTime;
                std::cout << "Hall Name: ";
                getline(std::cin, hallName);
                std::cout << "Show Time: ";
                getline(std::cin, showTime);

                Hall* hall = cinema.hallHead;
                Show* show = nullptr;
                while (hall && !show) {
                    if (hall->hallName == hallName) {
                        Show* s = hall->showHead;
                        while (s && !show) {
                            if (s->time == showTime) {
                                show = s;
                            }
                            s = s->next;
                        }
                    }
                    hall = hall->next;
                }

                if (show) {
                    displaySeats(show);
                    std::vector<std::string> seats;
                    std::string seatNum;

                    while (true) {
                        std::cout << "Seat Number to cancel (empty to finish): ";
                        getline(std::cin, seatNum);
                        if (seatNum.empty()) break;
                        seats.push_back(seatNum);
                    }

                    if (!seats.empty()) {
                        BookingSystem bs;
                        bs.cancelBooking(show, username, seats);
                        std::cout << "Booking canceled successfully.\n";
                    }
                } else {
                    std::cout << "Show not found\n";
                }
                break;
            }
            case 5: {
                std::cout << "\n--- Your Bookings ---\n";
                std::ifstream inFile(username + "_bookings.txt");
                std::string line;
                while (getline(inFile, line)) {
                    std::cout << line << "\n";
                }
                break;
            }
        }
    } while (choice != 0);

    DataStorage::saveMovies(cinema.movieHead);
    DataStorage::saveHalls(cinema.hallHead);
    DataStorage::saveShows(cinema.hallHead);

    return 0;
}