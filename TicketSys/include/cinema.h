#ifndef CINEMA_H
#define CINEMA_H

#include "hall.h"
#include "movie.h"
#include "notifications.h"

class Cinema {
public:
    std::string cinemaName;
    Movie* movieHead;
    Hall* hallHead;
    Cinema* next;

    Cinema(std::string name);
    void addMovie(std::string title, std::string language, std::string genre, std::string releaseDate);
    void addHall(std::string hallName);
    void deleteMovie(std::string title);
    void deleteShow(std::string hallName, std::string time);
    void displayShowtimes(std::string movieTitle);
};

#endif