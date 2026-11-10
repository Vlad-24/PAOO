#include <lucrare4/car.hpp>

Car::Car(const Engine& engine, int year)
    : engine_(engine),
      year_(year)
{
}

BodyAssignedCar::BodyAssignedCar(const Engine& engine, int year)
{
    engine_ = engine;
    year_ = year;
}

CarKey::CarKey(Car& car, int code)
    : car_(car),
      code_(code)
{
}

int CarKey::code() const
{
    return code_;
}

bool CarKey::opens(const Car& car) const
{
    return &car_ == &car;
}
