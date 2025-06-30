cmake_minimum_required(VERSION 3.10)
project(TicketSys)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

file(GLOB SOURCES "src/*.cpp")

add_executable(TicketSys ${SOURCES}
        include/booking.h
        include/bookingsystem.h
        include/seat.h
        src/cinema.cpp
        src/hall.cpp
        src/show.cpp
        src/seat.cpp
        src/movie.cpp
        src/bookingsystem.cpp
        src/booking.cpp
        include/datastorage.h
        src/datastorage.cpp)