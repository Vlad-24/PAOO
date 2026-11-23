#include <lucrare5/vehicle.hpp>

Vehicle::Vehicle(const std::string& model, int year)
    : model_(model),
      year_(year)
{
}

const std::string& Vehicle::model() const
{
    return model_;
}

int Vehicle::year() const
{
    return year_;
}
