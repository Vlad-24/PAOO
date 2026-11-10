#pragma once

#include <string>

class Chassis
{
public:
    explicit Chassis(const std::string& vin);

    Chassis(const Chassis&) = delete;
    Chassis& operator=(const Chassis&) = delete;

    const std::string& vin() const;

private:
    std::string vin_;
};

class Uncopyable
{
protected:
    Uncopyable()
    {
    }

    ~Uncopyable()
    {
    }

private:
    Uncopyable(const Uncopyable&);
    Uncopyable& operator=(const Uncopyable&);
};

class RegistrationCertificate : private Uncopyable
{
public:
    explicit RegistrationCertificate(const std::string& owner);

    const std::string& owner() const;

private:
    std::string owner_;
};
