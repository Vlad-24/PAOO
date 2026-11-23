#include <lucrare6/diagnostic.hpp>
#include <lucrare6/lift_lock.hpp>

#include <cassert>
#include <iostream>
#include <memory>
#include <mutex>
#include <stdexcept>
#include <type_traits>
#include <utility>

static_assert(!std::is_copy_constructible<LiftLock>::value, "A lift lock cannot be copied");
static_assert(!std::is_copy_assignable<LiftLock>::value, "A lift lock cannot be copy-assigned");

static void printTitle(const char* text)
{
    std::cout << "\n--- " << text << " ---\n";
}

static void scanCar(const char* model, bool scannerResponds)
{
    auto session = std::make_unique<DiagnosticSession>(model);
    if (scannerResponds)
    {
        session->scan();
        std::cout << "No faults found, returning early\n";
        return;
    }
    throw std::runtime_error("Scanner stopped responding");
}

static void demoAutomaticCleanup()
{
    printTitle("Item 13: RAII on early return and on exception");
    scanCar("Logan", true);
    try
    {
        scanCar("Duster", false);
    }
    catch (const std::runtime_error& error)
    {
        std::cout << "Caught: " << error.what() << "\n";
    }
}

static void demoSharedSession()
{
    printTitle("Item 13: shared_ptr releases the last owner's session");
    std::weak_ptr<DiagnosticSession> observer;
    {
        auto mechanic = std::make_shared<DiagnosticSession>("Spring");
        observer = mechanic;
        {
            auto electrician = mechanic;
            std::cout << "Owners after copying: " << mechanic.use_count() << "\n";
            electrician->scan();
        }
        std::cout << "Owners after the electrician leaves: " << mechanic.use_count() << "\n";
        assert(!observer.expired());
    }
    assert(observer.expired());
    std::cout << "Session released: " << std::boolalpha << observer.expired() << "\n";
}

static void demoNonCopyableLock()
{
    printTitle("Item 14: prohibit copying an exclusive lift lock");
    std::mutex lift;
    {
        LiftLock guard(lift);
        std::cout << "Lift reserved for the mechanic\n";
    }
    LiftLock nextGuard(lift);
    std::cout << "Next mechanic can reserve the lift\n";
}

static void demoSharedLock()
{
    printTitle("Item 14: share a lock and unlock with a custom deleter");
    std::mutex lift;
    {
        SharedLiftLock mechanic(lift);
        {
            SharedLiftLock assistant(mechanic);
            assert(assistant.owners() == 2);
            std::cout << "Guards sharing the lock: " << assistant.owners() << "\n";
        }
        assert(mechanic.owners() == 1);
        std::cout << "Guards still holding the lock: " << mechanic.owners() << "\n";
    }
    LiftLock nextGuard(lift);
    std::cout << "The last shared guard unlocked the lift\n";
}

static void demoDeepCopy()
{
    printTitle("Item 14: deep-copy the diagnostic readings");
    DiagnosticReadings original{300, 420};
    DiagnosticReadings copy(original);
    copy.setCode(0, 301);
    assert(original.code(0) == 300);
    std::cout << "Original code: " << original.code(0) << "\n";
    std::cout << "Copied reading after update: " << copy.code(0) << "\n";
}

static void demoOwnershipTransfer()
{
    printTitle("Items 13 and 14: transfer unique ownership with std::move");
    auto mechanic = std::make_unique<DiagnosticSession>("Sandero");
    auto electrician = std::move(mechanic);
    assert(!mechanic && electrician);
    std::cout << "Previous owner is empty: " << std::boolalpha << !mechanic << "\n";
    electrician->scan();
}

int main()
{
    demoAutomaticCleanup();
    demoSharedSession();
    demoNonCopyableLock();
    demoSharedLock();
    demoDeepCopy();
    demoOwnershipTransfer();
    return 0;
}
