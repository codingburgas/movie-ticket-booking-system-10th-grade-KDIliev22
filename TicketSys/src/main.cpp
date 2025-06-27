#include <iostream>
#include "cinema.h"

int main() {
    Cinema c("Cinema City");
    c.addMovie("Kill Bill", "English", "Action", "2003");
    c.addMovie("The Grand Budapest Hotel", "English", "Comedy", "2014");
    c.addHall("Hall A");
    c.addHall("Hall B");
    Hall* hall = c.hallHead;
    Movie* movie = c.movieHead;
    hall->addShow("10:00", movie);
    hall = hall->next;
    movie = movie->next;
    hall->addShow("12:00", movie);
    c.displayShowtimes("Kill Bill");
    c.displayShowtimes("The Grand Budapest Hotel");
    return 0;
}
