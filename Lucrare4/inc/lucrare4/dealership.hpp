#pragma once

extern int modelCount;

int catalogModelCount();

class Dealership
{
public:
    Dealership();

    int modelsFromGlobal() const;
    int modelsFromFunction() const;

private:
    int modelsFromGlobal_;
    int modelsFromFunction_;
};

extern Dealership dealership;
