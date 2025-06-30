#ifndef HALL_H
#define HALL_H

#include "show.h"

class Hall {
public:
    std::string hallName;
    Show* showHead;
    Hall* next;
    Hall(std::string name);
    void addShow(std::string time, Movie* movie);
};

#endif