#pragma once

#include <string>

class Vehicle
{
public:
    const std::string& model() const;
    int year() const;

protected:
    Vehicle(const std::string& model, int year);
    ~Vehicle() = default;

    Vehicle(const Vehicle&) = default;
    Vehicle(Vehicle&&) noexcept = default;
    Vehicle& operator=(const Vehicle&) = default;
    Vehicle& operator=(Vehicle&&) noexcept = default;

private:
    std::string model_;
    int year_;
};
