#include "datastorage.h"
#include <fstream>
#include <sstream>
#include <filesystem>

void DataStorage::saveMovies(Movie* movieHead) {
    std::ofstream file("movies.txt");
    Movie* current = movieHead;
    while (current) {
        file << current->title << "," << current->language << "," << current->genre << "," << current->releaseDate << "\n";
        current = current->next;
    }
}
Movie* DataStorage::loadMovies() {
    if (!std::filesystem::exists("movies.txt")) {
        return nullptr;
    }
    Movie* head = nullptr;
    Movie* tail = nullptr;
    std::ifstream file("movies.txt");
    std::string line;
    while (getline(file, line)) {
        std::stringstream ss(line);
        std::string title, language, genre, releaseDate;
        getline(ss, title, ',');
        getline(ss, language, ',');
        getline(ss, genre, ',');
        getline(ss, releaseDate);
        Movie* newMovie = new Movie(title, language, genre, releaseDate);
        if (!head) {
            head = tail = newMovie;
        } else {
            tail->next = newMovie;
            tail = newMovie;
        }
    }

    return head;
}

void DataStorage::saveHalls(Hall* hallHead) {
    std::ofstream file("halls.txt");
    Hall* current = hallHead;
    while (current) {
        file << current->hallName << "\n";
        current = current->next;
    }
}

Hall* DataStorage::loadHalls() {
    if (!std::filesystem::exists("halls.txt")) {
        return nullptr;
    }

    Hall* head = nullptr;
    Hall* tail = nullptr;
    std::ifstream file("halls.txt");
    std::string hallName;

    while (getline(file, hallName)) {
        Hall* newHall = new Hall(hallName);
        if (!head) {
            head = tail = newHall;
        } else {
            tail->next = newHall;
            tail = newHall;
        }
    }

    return head;
}

void DataStorage::saveShows(Hall* hallHead) {
    std::ofstream file("shows.txt");
    Hall* hall = hallHead;
    while (hall) {
        Show* show = hall->showHead;
        while (show) {
            file << hall->hallName << "," << show->time << ","
                 << show->movie->title << "\n";
            show = show->next;
        }
        hall = hall->next;
    }
}

void DataStorage::loadShows(Hall* hallHead, Movie* movieHead) {
    if (!std::filesystem::exists("shows.txt")) {
        return;
    }
    std::ifstream file("shows.txt");
    std::string line;
    while (getline(file, line)) {
        std::stringstream ss(line);
        std::string hallName, time, movieTitle;
        getline(ss, hallName, ',');
        getline(ss, time, ',');
        getline(ss, movieTitle);
        Hall* hall = hallHead;
        while (hall && hall->hallName != hallName) {
            hall = hall->next;
        }
        Movie* movie = movieHead;
        while (movie && movie->title != movieTitle) {
            movie = movie->next;
        }
        if (hall && movie) {
            hall->addShow(time, movie);
        }
    }
}