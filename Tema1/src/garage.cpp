#include <tema1/garage.hpp>

#include <cstring>
#include <iostream>

static char* copyString(const char* source)
{
    char* result = new char[std::strlen(source) + 1];
    std::strcpy(result, source);
    return result;
}

static const char* displayLocation(const char* location)
{
    return location ? location : "(moved)";
}

Garage::Garage(int id, const char* location, std::size_t carCount)
    : id_(id),
      location_(copyString(location)),
      mileages_(new int[carCount]()),
      carCount_(carCount)
{
    std::cout << "[ctor] " << location_ << ": " << carCount_ << " cars, mileages at "
              << mileages_ << "\n";
}

Garage::~Garage()
{
    if (mileages_)
    {
        std::cout << "[dtor] " << location_ << ": delete[] " << mileages_ << "\n";
    }
    else
    {
        std::cout << "[dtor] (moved): nothing to free\n";
    }
    delete[] location_;
    delete[] mileages_;
}

Garage::Garage(const Garage& other)
    : id_(other.id_),
      location_(other.location_ ? copyString(other.location_) : nullptr),
      mileages_(other.mileages_ ? new int[other.carCount_] : nullptr),
      carCount_(other.carCount_)
{
    if (mileages_)
    {
        std::memcpy(mileages_, other.mileages_, carCount_ * sizeof(int));
    }
    std::cout << "[copy] " << displayLocation(location_) << ": " << other.mileages_
              << " -> " << mileages_ << "\n";
}

Garage::Garage(Garage&& other) noexcept
    : id_(other.id_),
      location_(other.location_),
      mileages_(other.mileages_),
      carCount_(other.carCount_)
{
    other.location_ = nullptr;
    other.mileages_ = nullptr;
    other.carCount_ = 0;
    std::cout << "[move] " << location_ << ": takes over " << mileages_ << "\n";
}

void Garage::setLocation(const char* location)
{
    char* newLocation = copyString(location);
    delete[] location_;
    location_ = newLocation;
}

void Garage::setMileage(std::size_t car, int mileage)
{
    if (car < carCount_ && mileage >= mileages_[car])
    {
        mileages_[car] = mileage;
    }
}

void Garage::print() const
{
    std::cout << displayLocation(location_);
    for (std::size_t i = 0; i < carCount_; ++i)
    {
        std::cout << " " << mileages_[i];
    }
    std::cout << (carCount_ ? " km\n" : "\n");
}
