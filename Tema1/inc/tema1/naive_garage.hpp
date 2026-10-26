#pragma once

class NaiveGarage
{
public:
    explicit NaiveGarage(const char* location);
    ~NaiveGarage();

    void setLocation(const char* location);
    const char* getLocation() const;
    const void* bufferAddress() const;

private:
    char* location_;
};
