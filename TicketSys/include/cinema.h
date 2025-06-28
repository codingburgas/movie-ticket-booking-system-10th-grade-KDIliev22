#ifndef CINEMA_H
#define CINEMA_H

#include "hall.h"
#include "movie.h"

class Cinema {
public:
    std::string cinemaName;
    Movie* movieHead;
    Hall* hallHead;
    Cinema* next;
    Cinema(std::string name) : cinemaName(name), movieHead(nullptr), hallHead(nullptr), next(nullptr) {}
    void addMovie(std::string title, std::string language, std::string genre, std::string releaseDate) {
        Movie* newMovie = new Movie(title, language, genre, releaseDate);
        if (!movieHead) movieHead = newMovie;
        else {
            Movie* temp = movieHead;
            while (temp->next) temp = temp->next;
            temp->next = newMovie;
        }
    }
    void addHall(std::string hallName) {
        Hall* newHall = new Hall(hallName);
        if (!hallHead) hallHead = newHall;
        else {
            Hall* temp = hallHead;
            while (temp->next) temp = temp->next;
            temp->next = newHall;
        }
    }
    void displayShowtimes(std::string movieTitle) {
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
};

#endif //CINEMA_H
