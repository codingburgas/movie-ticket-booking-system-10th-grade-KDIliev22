#include "hall.h"

Hall::Hall(std::string name) : hallName(name), showHead(nullptr), next(nullptr) {}

void Hall::addShow(std::string time, Movie* movie) {
    Show* newShow = new Show(time, movie);
    if (!showHead) showHead = newShow;
    else {
        Show* temp = showHead;
        while (temp->next) temp = temp->next;
        temp->next = newShow;
    }
}