#include "Car.h"
#include <cmath>
#include <iostream>

Car::Car(const FuelTank &fuelTank, const Engine &engine, const Tyre &tyre1, const Tyre &tyre2, const Tyre &tyre3, const Tyre &tyre4, const Battery &battery, int mileage, int weight)
    : carFuelTank(fuelTank), carEngine(engine),
      tyre1(tyre1), tyre2(tyre2), tyre3(tyre3), tyre4(tyre4),
      carBattery(battery), carMileage(mileage), carWeight(weight)
{
}

const FuelTank &Car::getFuelTank() const
{
    return carFuelTank;
    // TODO: insert return statement here
}

void Car::drive(double km)
{
    carMileage += km;

    int fuel = carFuelTank.getCurrentFuel();

    double fuelPerKilometer = (log(carEngine.getHp()) / log(3) + log(carWeight) / log(8)) / 100;

    double usedFuel = km * fuelPerKilometer;

    if (fuel > usedFuel)
        carFuelTank.use(usedFuel);
    else
        std::cout << "Not enough fuel" << std::endl;
}

bool Car::checkFuel(double km)
{
    double fuelPerKilometer = (log(carEngine.getHp()) / log(3) + log(carWeight) / log(8)) / 100;

    double usedFuel = km * fuelPerKilometer;

    if (getFuelTank().getCurrentFuel() > usedFuel)
        return true;

    return false;
}

Car *dragRace(Car *car1, Car *car2)
{
    const double dragDistance = 0.4;

    if (car1->checkFuel(dragDistance) && car2->checkFuel(dragDistance))
        return getWinner(car1, car2);
    else if (car1->checkFuel(dragDistance) && !car2->checkFuel(dragDistance))
        return car1;
    else if (!car1->checkFuel(dragDistance) && car2->checkFuel(dragDistance))
        return car2;
    else if (!car1->checkFuel(dragDistance) && !car2->checkFuel(dragDistance))
        return nullptr;

    return nullptr;
}

Car *getWinner(Car *car1, Car *car2)
{
    double car1Characteristic = car1->getHp() / car1->getCarWeight();
    double car2Characteristic = car2->getHp() / car2->getCarWeight();

    if (car1Characteristic > car2Characteristic)
        return car1;
    else
        return car2;

    return nullptr;
}
