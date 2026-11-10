#pragma once

#include <lucrare4/engine.hpp>

class Car
{
public:
    Car(const Engine& engine, int year);

private:
    Engine engine_;
    int year_;
};

class BodyAssignedCar
{
public:
    BodyAssignedCar(const Engine& engine, int year);

private:
    Engine engine_;
    int year_;
};

class CarKey
{
public:
    CarKey(Car& car, int code);

    int code() const;
    bool opens(const Car& car) const;

private:
    Car& car_;
    const int code_;
};
