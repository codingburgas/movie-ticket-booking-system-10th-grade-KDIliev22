cmake_minimum_required(VERSION 3.10)
project(Chrome)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

file(GLOB SOURCES "src/*.cpp")

add_executable(Chrome ${SOURCES} #[[ krustih go taka za da bachka v dsk prosti mi]]
        include/precompiler.h)

