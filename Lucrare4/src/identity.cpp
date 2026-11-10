#include <lucrare4/identity.hpp>

Chassis::Chassis(const std::string& vin)
    : vin_(vin)
{
}

const std::string& Chassis::vin() const
{
    return vin_;
}

RegistrationCertificate::RegistrationCertificate(const std::string& owner)
    : owner_(owner)
{
}

const std::string& RegistrationCertificate::owner() const
{
    return owner_;
}
