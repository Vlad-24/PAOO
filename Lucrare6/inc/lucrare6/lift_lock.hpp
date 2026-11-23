#pragma once

#include <memory>
#include <mutex>

class LiftLock
{
public:
    explicit LiftLock(std::mutex& lift);
    ~LiftLock() noexcept;

    LiftLock(const LiftLock&) = delete;
    LiftLock& operator=(const LiftLock&) = delete;

private:
    std::mutex& lift_;
};

class SharedLiftLock
{
public:
    explicit SharedLiftLock(std::mutex& lift);
    long owners() const noexcept;

private:
    std::shared_ptr<std::mutex> lift_;
};
