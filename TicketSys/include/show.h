#ifndef SHOW_H
#define SHOW_H

#include "movie.h"
#include "seat.h"

class Show {
public:
    std::string time;
    Movie* movie;
    Seat* seatHead;
    Show* next;
    Show(std::string t, Movie* m);
    void addSeat(std::string number, std::string type);
    Seat* findSeat(std::string number);
};

#endif