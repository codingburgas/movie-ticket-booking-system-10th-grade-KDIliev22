#ifndef HALL_H
#define HALL_H

#include "show.h"

class Hall {
public:
    std::string hallName;
    Show* showHead;
    Hall* next;
    Hall(std::string name) : hallName(name), showHead(nullptr), next(nullptr) {}
    void addShow(std::string time, Movie* movie) {
        Show* newShow = new Show(time, movie);
        if (!showHead) showHead = newShow;
        else {
            Show* temp = showHead;
            while (temp->next) temp = temp->next;
            temp->next = newShow;
        }
    }
};

#endif //HALL_H
