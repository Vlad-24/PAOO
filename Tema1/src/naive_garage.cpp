#include <tema1/naive_garage.hpp>

#include <cstring>
#include <iostream>

NaiveGarage::NaiveGarage(const char* location)
    : location_(new char[std::strlen(location) + 1])
{
    std::strcpy(location_, location);
    std::cout << "[ctor] " << location_ << " at " << static_cast<const void*>(location_) << "\n";
}

NaiveGarage::~NaiveGarage()
{
    std::cout << "[dtor] delete[] " << static_cast<const void*>(location_) << "\n";
    delete[] location_;
}

void NaiveGarage::setLocation(const char* location)
{
    std::strncpy(location_, location, std::strlen(location_));
}

const char* NaiveGarage::getLocation() const
{
    return location_;
}

const void* NaiveGarage::bufferAddress() const
{
    return location_;
}
