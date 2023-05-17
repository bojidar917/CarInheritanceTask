#include "CarPart.h"

class FuelTank : public CarPart
{
public:
    FuelTank();
    FuelTank(const char *id, const char *manifacturerName, const char *description, const double fullCapacity);
    FuelTank(const FuelTank &other);
    FuelTank &operator=(const FuelTank &other);

    double getFullCapacity() const { return fullCapacity; }
    double getCurrentFuel() const { return currentFuel; }

    void use(double amount);
    void fill(double amount);

    bool checkFuel(double km, int hp, double carWeight);

private:
    double fullCapacity;
    double currentFuel;

    void setFullCapacity(double amount);
};