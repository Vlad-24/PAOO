#include <lucrare6/lift_lock.hpp>

static std::shared_ptr<std::mutex> lockLift(std::mutex& lift)
{
    lift.lock();
    return std::shared_ptr<std::mutex>(&lift, [](std::mutex* lockedLift) noexcept {
        lockedLift->unlock();
    });
}

LiftLock::LiftLock(std::mutex& lift)
    : lift_(lift)
{
    lift_.lock();
}

LiftLock::~LiftLock() noexcept
{
    lift_.unlock();
}

SharedLiftLock::SharedLiftLock(std::mutex& lift)
    : lift_(lockLift(lift))
{
}

long SharedLiftLock::owners() const noexcept
{
    return lift_.use_count();
}
