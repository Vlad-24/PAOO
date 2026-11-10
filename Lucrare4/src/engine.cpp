#include <lucrare4/engine.hpp>

#include <iostream>

Engine::Engine()
    : code_("none")
{
    std::cout << "[default] Engine " << code_ << "\n";
}

Engine::Engine(const std::string& code)
    : code_(code)
{
}

Engine::Engine(const Engine& other)
    : code_(other.code_)
{
    std::cout << "[copy] Engine " << code_ << "\n";
}

Engine& Engine::operator=(const Engine& other)
{
    code_ = other.code_;
    std::cout << "[assign] Engine " << code_ << "\n";
    return *this;
}
