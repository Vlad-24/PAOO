#include <lucrare5/service_car.hpp>

#include <iostream>
#include <utility>

ServiceCar::ServiceCar(const std::string& model, int year, int serviceBay,
                       const Inspection& inspection)
    : Vehicle(model, year),
      serviceBay_(serviceBay),
      inspection_(std::make_unique<Inspection>(inspection))
{
}

ServiceCar::ServiceCar(const ServiceCar& other)
    : Vehicle(other),
      serviceBay_(other.serviceBay_),
      inspection_(other.inspection_ ? std::make_unique<Inspection>(*other.inspection_) : nullptr)
{
}

ServiceCar& ServiceCar::operator=(const ServiceCar& other)
{
    if (this == &other)
    {
        return *this;
    }

    auto newInspection = other.inspection_ ? std::make_unique<Inspection>(*other.inspection_) : nullptr;
    Vehicle::operator=(other);
    serviceBay_ = other.serviceBay_;
    inspection_ = std::move(newInspection);
    return *this;
}

ServiceCar& ServiceCar::operator=(ServiceCar&& other) noexcept
{
    if (this != &other)
    {
        Vehicle::operator=(std::move(other));
        serviceBay_ = other.serviceBay_;
        inspection_ = std::move(other.inspection_);
    }
    return *this;
}

int ServiceCar::serviceBay() const
{
    return serviceBay_;
}

const Inspection* ServiceCar::inspection() const
{
    return inspection_.get();
}

void ServiceCar::updateInspection(const Inspection& inspection)
{
    if (inspection_)
    {
        *inspection_ = inspection;
    }
    else
    {
        inspection_ = std::make_unique<Inspection>(inspection);
    }
}

void ServiceCar::print() const
{
    if (inspection_)
    {
        std::cout << model() << " (" << year() << "), bay " << serviceBay_
                  << ", " << inspection_->mileage << " km, " << inspection_->faultCount
                  << " faults\n";
    }
    else
    {
        std::cout << "(no inspection)\n";
    }
}
