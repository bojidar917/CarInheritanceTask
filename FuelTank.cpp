#include "FuelTank.h"
#include "CarPart.cpp"
#include "InsufficientFuelError.cpp"

FuelTank::FuelTank()
{
}

FuelTank::FuelTank(const char *id, const char *manifacturerName, const char *description, const double fullCapacity)
    : CarPart(id, manifacturerName, description)
{
    setFullCapacity(fullCapacity);
}

FuelTank::FuelTank(const FuelTank &other)
    : CarPart(other)
{
    this->fullCapacity = other.fullCapacity;
    this->currentFuel = other.currentFuel;
}

FuelTank &FuelTank::operator=(const FuelTank &other)
{
    if (this != &other)
    {
        CarPart::operator=(other);
        this->fullCapacity = other.fullCapacity;
        this->currentFuel = other.currentFuel;
    }

    return *this;
}

void FuelTank::use(double amount)
{
    // custom exception handling
    if (amount > currentFuel)
    {
        throw insufficient_fuel_error("Insufficient fuel to perform the operation.");
    }
    else
    {
        this->currentFuel -= amount;
    }

    // when I use the function always use the try and catch as follows:
    // try {
    //     myFuelTank.use(10.0); // Example usage of the use() function
    // }
    // catch (const insufficient_fuel_error &e)
    // {
    //     std::cerr << "Error: " << e.what() << std::endl;
    //     // Handle the insufficient fuel error appropriately
    // }
}

void FuelTank::fill(double amount)
{
    int freeSpace = this->fullCapacity - this->currentFuel;
    if (freeSpace < amount)
        this->currentFuel = this->fullCapacity;
    else
        this->currentFuel += amount;
}

void FuelTank::setFullCapacity(double amount)
{
    if (amount < 0)
        amount = 0;

    this->fullCapacity = amount;
    this->currentFuel = amount;
}
