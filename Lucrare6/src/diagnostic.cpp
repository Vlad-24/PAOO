#include <lucrare6/diagnostic.hpp>

#include <cstdio>

DiagnosticSession::DiagnosticSession(const std::string& model)
    : model_(model)
{
    std::printf("[connect] %s\n", model_.c_str());
}

DiagnosticSession::~DiagnosticSession() noexcept
{
    std::printf("[disconnect] %s\n", model_.c_str());
}

void DiagnosticSession::scan() const
{
    std::printf("[scan] %s\n", model_.c_str());
}

DiagnosticReadings::DiagnosticReadings(std::initializer_list<int> codes)
    : codes_(codes)
{
}

void DiagnosticReadings::setCode(std::size_t index, int code)
{
    codes_.at(index) = code;
}

int DiagnosticReadings::code(std::size_t index) const
{
    return codes_.at(index);
}
