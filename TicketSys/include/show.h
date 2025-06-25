#ifndef SHOW_H
#define SHOW_H

#include <string>
#include <vector>
#include "seat.h"

class Show {
private:
    std::string movieTitle;
    std::string time;
    std::vector<Seat> seats;
public:
    Show();
    Show(const std::string& movieTitle, const std::string& time);
    std::string getMovieTitle() const;
    std::string getTime() const;
    void generateSeats(int count);
    void displaySeats() const;
    bool bookSeat(int seatNumber);
    bool isSeatAvailable(int seatNumber) const;
    Seat getSeat(int seatNumber) const;
};

#endif
