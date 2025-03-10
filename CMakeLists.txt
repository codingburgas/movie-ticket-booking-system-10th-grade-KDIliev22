cmake_minimum_required(VERSION 3.29)
project(movie_ticket_booking_system_10th_grade_KDIliev22)
set(FTXUI_DIR "${CMAKE_SOURCE_DIR}/third_party/ftxui/")
add_subdirectory(${FTXUI_DIR})
include_directories(third_party/ftxui/include)

set(CMAKE_CXX_STANDARD 14)

include_directories(src)
include_directories(src/app)
include_directories(src/database)
include_directories(src/models)
include_directories(src/services)
include_directories(src/ui)
include_directories(src/utils)

add_executable(movie_ticket_booking_system_10th_grade_KDIliev22
        src/app/App.cpp
        src/app/App.h
        src/app/main.cpp
        src/database/Database.cpp
        src/database/Database.h
        src/models/Booking.cpp
        src/models/Booking.h
        src/models/Movie.cpp
        src/models/Movie.h
        src/models/User.cpp
        src/models/User.h
        src/services/BookingService.cpp
        src/services/BookingService.h
        src/services/PaymentService.cpp
        src/services/PaymentService.h
        src/ui/BookingUI.cpp
        src/ui/BookingUI.h
        src/ui/Menu.cpp
        src/ui/Menu.h
        src/utils/Config.cpp
        src/utils/Config.h
        src/utils/Logger.cpp
        src/utils/Logger.h
        tests/test_booking.cpp
        tests/test_database.cpp
        tests/test_main.cpp)
