#include <lucrare4/dealership.hpp>

Dealership::Dealership()
    : modelsFromGlobal_(modelCount),
      modelsFromFunction_(catalogModelCount())
{
}

int Dealership::modelsFromGlobal() const
{
    return modelsFromGlobal_;
}

int Dealership::modelsFromFunction() const
{
    return modelsFromFunction_;
}

Dealership dealership;
