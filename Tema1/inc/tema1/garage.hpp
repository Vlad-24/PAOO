#pragma once

#include <cstddef>

class Garage
{
public:
    Garage(int id, const char* location, std::size_t carCount);
    ~Garage();

    Garage(const Garage& other);
    Garage(Garage&& other) noexcept;

    Garage& operator=(const Garage&) = delete;
    Garage& operator=(Garage&&) = delete;

    void setLocation(const char* location);
    void setMileage(std::size_t car, int mileage);
    void print() const;

private:
    const int id_;
    char* location_;
    int* mileages_;
    std::size_t carCount_;
};
