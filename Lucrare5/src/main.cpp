#include <lucrare5/service_car.hpp>

#include <cassert>
#include <iostream>
#include <utility>

static void printTitle(const char* text)
{
    std::cout << "\n--- " << text << " ---\n";
}

static void checkCopy(const ServiceCar& copy, const ServiceCar& original)
{
    const Inspection* copiedInspection = copy.inspection();
    const Inspection* originalInspection = original.inspection();
    const bool matches = copy.model() == original.model() &&
                         copy.year() == original.year() &&
                         copy.serviceBay() == original.serviceBay() &&
                         copiedInspection && originalInspection &&
                         copiedInspection != originalInspection &&
                         copiedInspection->mileage == originalInspection->mileage &&
                         copiedInspection->faultCount == originalInspection->faultCount;
    assert(matches);
    std::cout << "All fields copied, separate inspections: " << std::boolalpha << matches << "\n";
}

static void demoChainedAssignment()
{
    printTitle("Item 10: return a reference to *this");
    ServiceCar first("Logan", 2019, 1, {98000, 2});
    ServiceCar second("Sandero", 2021, 2, {52000, 1});
    ServiceCar third("Duster", 2023, 3, {31000, 0});

    ServiceCar& result = (first = second = third);
    std::cout << "first = second = third\n";
    std::cout << "Result refers to first: " << std::boolalpha << (&result == &first) << "\n";
    assert(&result == &first);
    first.print();
    second.print();
    third.print();
    checkCopy(first, third);
    checkCopy(second, third);
}

static void demoSelfAssignment()
{
    printTitle("Item 11: self-assignment through an alias");
    ServiceCar car("Spring", 2022, 4, {26000, 1});
    const ServiceCar& alias = car;
    const Inspection* originalInspection = car.inspection();

    car = alias;
    assert(car.model() == "Spring" && car.year() == 2022 && car.serviceBay() == 4);
    assert(car.inspection() == originalInspection);
    assert(car.inspection()->mileage == 26000 && car.inspection()->faultCount == 1);
    std::cout << "car = alias preserves the inspection: " << std::boolalpha
              << (car.inspection() == originalInspection) << "\n";
    car.print();
}

static void demoCopyAllParts()
{
    printTitle("Item 12: copy base class and derived members");
    ServiceCar original("Duster", 2020, 2, {68000, 3});
    ServiceCar copy(original);
    ServiceCar assigned("Logan", 2017, 5, {141000, 7});
    assigned = original;

    std::cout << "Copy constructor: ";
    checkCopy(copy, original);
    std::cout << "Copy assignment: ";
    checkCopy(assigned, original);

    copy.updateInspection({68000, 0});
    assert(original.inspection()->faultCount == 3);
    std::cout << "Original: ";
    original.print();
    std::cout << "Copy after inspection update: ";
    copy.print();
}

static void demoMoveAssignment()
{
    printTitle("Move assignment: transfer the inspection");
    ServiceCar source("Sandero", 2024, 3, {19000, 1});
    ServiceCar target("Logan", 2016, 1, {170000, 4});
    const Inspection* inspection = source.inspection();

    ServiceCar& result = (target = std::move(source));
    assert(&result == &target);
    assert(target.inspection() == inspection && source.inspection() == nullptr);
    assert(target.model() == "Sandero" && target.year() == 2024 && target.serviceBay() == 3);
    std::cout << "Target owns the same inspection: " << std::boolalpha
              << (target.inspection() == inspection && &result == &target) << "\n";
    std::cout << "Target: ";
    target.print();
    std::cout << "Source: ";
    source.print();
}

int main()
{
    demoChainedAssignment();
    demoSelfAssignment();
    demoCopyAllParts();
    demoMoveAssignment();
    return 0;
}
