#include <lucrare4/car.hpp>
#include <lucrare4/dealership.hpp>
#include <lucrare4/engine.hpp>
#include <lucrare4/identity.hpp>

#include <iostream>
#include <type_traits>

static_assert(!std::is_default_constructible<Car>::value, "Car has a user-declared constructor");
static_assert(std::is_copy_constructible<Car>::value, "Car copy constructor is generated");
static_assert(std::is_copy_assignable<Car>::value, "Car copy assignment is generated");
static_assert(std::is_copy_constructible<CarKey>::value, "CarKey copy constructor is generated");
static_assert(!std::is_copy_assignable<CarKey>::value, "CarKey has a reference and a const member");
static_assert(!std::is_copy_constructible<Chassis>::value, "Chassis copy constructor is deleted");
static_assert(!std::is_copy_assignable<Chassis>::value, "Chassis copy assignment is deleted");
static_assert(!std::is_copy_constructible<RegistrationCertificate>::value, "Uncopyable copy constructor is private");
static_assert(!std::is_copy_assignable<RegistrationCertificate>::value, "Uncopyable copy assignment is private");

static void printTitle(const char* text)
{
    std::cout << "\n--- " << text << " ---\n";
}

static void printStep(const char* statement)
{
    std::cout << statement << "\n";
}

static const char* yesNo(bool value)
{
    return value ? "yes" : "no";
}

int main()
{
    Engine diesel("1.5 dCi");
    Engine petrol("1.0 TCe");

    printTitle("Item 4: initialization list vs assignment");
    printStep("Car dacia(diesel, 2019);");
    Car dacia(diesel, 2019);
    printStep("BodyAssignedCar logan(diesel, 2019);");
    BodyAssignedCar logan(diesel, 2019);

    printTitle("Item 4: static objects in different files");
    std::cout << "dealership reads global modelCount: " << dealership.modelsFromGlobal() << "\n";
    std::cout << "dealership calls catalogModelCount(): " << dealership.modelsFromFunction() << "\n";

    printTitle("Item 5: generated functions of Car");
    printStep("Car renault(petrol, 2021);");
    Car renault(petrol, 2021);
    printStep("Car copy(dacia);");
    Car copy(dacia);
    printStep("copy = renault;");
    copy = renault;
    std::cout << "Car default constructible: " << yesNo(std::is_default_constructible<Car>::value) << "\n";

    printTitle("Item 5: CarKey with reference and const member");
    CarKey key(dacia, 4821);
    CarKey duplicate(key);
    std::cout << "duplicate of key " << key.code() << " opens dacia: " << yesNo(duplicate.opens(dacia)) << "\n";
    std::cout << "CarKey copy constructible: " << yesNo(std::is_copy_constructible<CarKey>::value) << "\n";
    std::cout << "CarKey copy assignable: " << yesNo(std::is_copy_assignable<CarKey>::value) << "\n";

    printTitle("Item 6: Chassis with = delete");
    Chassis chassis("UU1HSDACN12345678");
    std::cout << "chassis " << chassis.vin() << " copyable: "
              << yesNo(std::is_copy_constructible<Chassis>::value) << ", assignable: "
              << yesNo(std::is_copy_assignable<Chassis>::value) << "\n";

    printTitle("Item 6: RegistrationCertificate with private Uncopyable");
    RegistrationCertificate certificate("Vlad");
    std::cout << "certificate of " << certificate.owner() << " copyable: "
              << yesNo(std::is_copy_constructible<RegistrationCertificate>::value) << ", assignable: "
              << yesNo(std::is_copy_assignable<RegistrationCertificate>::value) << "\n";
    return 0;
}
