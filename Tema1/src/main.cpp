#include <tema1/garage.hpp>
#include <tema1/naive_garage.hpp>

#include <cstring>
#include <iostream>
#include <utility>

static void printTitle(const char* text)
{
    std::cout << "\n--- " << text << " ---\n";
}

static void demoConstructorAndEncapsulation()
{
    printTitle("1. Constructor and encapsulation");
    Garage garage(1, "Iasi", 3);
    garage.setMileage(0, 12000);
    garage.setMileage(1, 45000);
    garage.setMileage(2, 30000);
    garage.setMileage(0, 8000);
    garage.setMileage(7, 1000);
    garage.print();
}

static void demoDestructor()
{
    printTitle("2. Destructor");
    Garage garage(2, "Cluj", 1000);
}

static void demoShallowCopy()
{
    printTitle("3. Without copy constructor");
    NaiveGarage original("Iasi");
    NaiveGarage* copy = new NaiveGarage(original);
    copy->setLocation("Arad");
    std::cout << "copy renamed to Arad -> original is now: " << original.getLocation()
              << " (same address " << copy->bufferAddress() << ")\n";
    std::cout << "(run with --double-free to see the crash)\n";
}

static void demoDoubleFree()
{
    printTitle("Double free");
    NaiveGarage first("Brasov");
    NaiveGarage second(first);
}

static void demoCopyConstructor()
{
    printTitle("4. Copy constructor");
    Garage original(3, "Iasi", 2);
    original.setMileage(0, 70000);
    original.setMileage(1, 90000);
    Garage copy(original);
    copy.setLocation("Arad");
    copy.setMileage(0, 80000);
    std::cout << "original: ";
    original.print();
    std::cout << "copy: ";
    copy.print();
}

static void demoMoveConstructor()
{
    printTitle("5. Move constructor");
    Garage source(4, "Iasi", 2);
    source.setMileage(0, 70000);
    source.setMileage(1, 90000);
    Garage moved(std::move(source));
    std::cout << "source: ";
    source.print();
    std::cout << "moved: ";
    moved.print();
}

int main(int argc, char* argv[])
{
    std::cout << std::unitbuf;

    if (argc > 1 && std::strcmp(argv[1], "--double-free") == 0)
    {
        demoDoubleFree();
        return 0;
    }

    demoConstructorAndEncapsulation();
    demoDestructor();
    demoShallowCopy();
    demoCopyConstructor();
    demoMoveConstructor();
    return 0;
}
