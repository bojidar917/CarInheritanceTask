#include "FuelTank.cpp"
#include "Engine.cpp"
#include "Tyre.cpp"
#include "Battery.cpp"

class Car
{
public:
    Car() = default;

    Car(const FuelTank &fuelTank, const Engine &engine,
        const Tyre &tyre1, const Tyre &tyre2, const Tyre &tyre3, const Tyre &tyre4,
        const Battery &battery, int mileage, int weight);

    const FuelTank &getFuelTank() const;
    const double &getHp() const { return carEngine.getHp(); }
    const int getCarWeight() const { return carWeight; }

    void drive(double km);

    bool checkFuel(double km);

private:
    FuelTank carFuelTank;
    Engine carEngine;
    Tyre tyre1;
    Tyre tyre2;
    Tyre tyre3;
    Tyre tyre4;
    Battery carBattery;
    int carMileage;
    int carWeight;
};

Car *dragRace(Car *car1, Car *car2);

Car *getWinner(Car *car1, Car *car2);