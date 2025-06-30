#include "booking.h"

Booking::Booking(std::string name, std::string payment, std::string type, Show* show) : customerName(name), paymentMethod(payment), bookingType(type), showBooked(show), next(nullptr) {}