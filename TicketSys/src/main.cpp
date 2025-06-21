#include <iostream>
#include "cinema.h"

int main() {
    Cinema c("Cinema City", "Burgas");
    std::cout << "Cinema: " << c.getName() << ", City: " << c.getCity() << "\n";
    return 0;
}

