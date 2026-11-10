#pragma once

#include <string>

class Engine
{
public:
    Engine();
    explicit Engine(const std::string& code);
    Engine(const Engine& other);
    Engine& operator=(const Engine& other);

private:
    std::string code_;
};
