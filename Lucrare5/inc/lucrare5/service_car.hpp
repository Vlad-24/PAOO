#pragma once

#include <lucrare5/vehicle.hpp>

#include <memory>

struct Inspection
{
    int mileage;
    int faultCount;
};

class ServiceCar : public Vehicle
{
public:
    ServiceCar(const std::string& model, int year, int serviceBay, const Inspection& inspection);

    ServiceCar(const ServiceCar& other);
    ServiceCar(ServiceCar&&) noexcept = default;
    ServiceCar& operator=(const ServiceCar& other);
    ServiceCar& operator=(ServiceCar&& other) noexcept;

    int serviceBay() const;
    const Inspection* inspection() const;
    void updateInspection(const Inspection& inspection);
    void print() const;

private:
    int serviceBay_;
    std::unique_ptr<Inspection> inspection_;
};
