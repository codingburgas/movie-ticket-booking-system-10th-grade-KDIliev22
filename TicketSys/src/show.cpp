#include "show.h"

Show::Show(std::string t, Movie* m) : time(t), movie(m), seatHead(nullptr), next(nullptr) {}

void Show::addSeat(std::string number, std::string type) {
    Seat* newSeat = new Seat(number, type);
    if (!seatHead) seatHead = newSeat;
    else {
        Seat* temp = seatHead;
        while (temp->next) temp = temp->next;
        temp->next = newSeat;
    }
}

Seat* Show::findSeat(std::string number) {
    Seat* temp = seatHead;
    while (temp) {
        if (temp->seatNumber == number) return temp;
        temp = temp->next;
    }
    return nullptr;
}