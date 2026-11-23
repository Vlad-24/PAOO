#pragma once

#include <cstddef>
#include <initializer_list>
#include <string>
#include <vector>

class DiagnosticSession
{
public:
    explicit DiagnosticSession(const std::string& model);
    ~DiagnosticSession() noexcept;

    DiagnosticSession(const DiagnosticSession&) = delete;
    DiagnosticSession& operator=(const DiagnosticSession&) = delete;

    void scan() const;

private:
    std::string model_;
};

class DiagnosticReadings
{
public:
    DiagnosticReadings(std::initializer_list<int> codes);
    void setCode(std::size_t index, int code);
    int code(std::size_t index) const;

private:
    std::vector<int> codes_;
};
