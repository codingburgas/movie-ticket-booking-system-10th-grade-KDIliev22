#ifndef SHOW_H
#define SHOW_H

#include <string>
#include "movie.h"
#include "seat.h"

class Show {
public:
    std::string time;
    Movie* movie;
    Seat* seatHead;
    Show* next;
    Show(std::string t, Movie* m) : time(t), movie(m), seatHead(nullptr), next(nullptr) {}
    void addSeat(std::string number, std::string type) {
        Seat* newSeat = new Seat(number, type);
        if (!seatHead) seatHead = newSeat;
        else {
            Seat* temp = seatHead;
            while (temp->next) temp = temp->next;
            temp->next = newSeat;
        }
    }
    Seat* findSeat(std::string number) {
        Seat* temp = seatHead;
        while (temp) {
            if (temp->seatNumber == number)
                return temp;
            temp = temp->next;
        }
        return nullptr;
    }
};

#endif // SHOW_H