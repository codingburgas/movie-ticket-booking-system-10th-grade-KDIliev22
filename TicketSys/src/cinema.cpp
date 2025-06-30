#include "cinema.h"
#include <iostream>

Cinema::Cinema(std::string name) : cinemaName(name), movieHead(nullptr), hallHead(nullptr), next(nullptr) {}

void Cinema::addMovie(std::string title, std::string language, std::string genre, std::string releaseDate) {
    Movie* newMovie = new Movie(title, language, genre, releaseDate);
    if (!movieHead) {
        movieHead = newMovie;
    } else {
        Movie* temp = movieHead;
        while (temp->next) temp = temp->next;
        temp->next = newMovie;
    }
    NotificationSystem::addNotification("New movie released: " + title);
}

void Cinema::addHall(std::string hallName) {
    Hall* newHall = new Hall(hallName);
    if (!hallHead) {
        hallHead = newHall;
    } else {
        Hall* temp = hallHead;
        while (temp->next) temp = temp->next;
        temp->next = newHall;
    }
}

void Cinema::deleteMovie(std::string title) {
    Movie* current = movieHead;
    Movie* prev = nullptr;
    while (current && current->title != title) {
        prev = current;
        current = current->next;
    }
    if (!current) return;
    if (!prev) movieHead = current->next;
    else prev->next = current->next;
    delete current;
}

void Cinema::deleteShow(std::string hallName, std::string time) {
    Hall* hall = hallHead;
    while (hall && hall->hallName != hallName) hall = hall->next;
    if (!hall) return;

    Show* current = hall->showHead;
    Show* prev = nullptr;
    while (current && current->time != time) {
        prev = current;
        current = current->next;
    }
    if (!current) return;
    if (!prev) hall->showHead = current->next;
    else prev->next = current->next;
    delete current;
}

void Cinema::displayShowtimes(std::string movieTitle) {
    Movie* movie = movieHead;
    while (movie) {
        if (movie->title == movieTitle) {
            std::cout << "Showtimes for " << movieTitle << ":\n";
            Hall* hall = hallHead;
            while (hall) {
                Show* show = hall->showHead;
                while (show) {
                    if (show->movie == movie) {
                        std::cout << "Hall: " << hall->hallName << " at " << show->time << "\n";
                    }
                    show = show->next;
                }
                hall = hall->next;
            }
            return;
        }
        movie = movie->next;
    }
    std::cout << "Movie not found.\n";
}