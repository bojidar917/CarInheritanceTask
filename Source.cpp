#include <iostream>
#include "CarPart.cpp"
#include "FuelTank.cpp"
#include "Engine.cpp"
#include "Tyre.cpp"
#include "Battery.cpp"
#include "Car.cpp"

int main()
{
    Car dodgeChallengerDemon170(FuelTank("customName", "Dodge", "Large fuelTank for drag cars", 70),
                                Engine("customName", "Dodge", "Big engine for drag cars", 1050),
                                Tyre("315/50R-17/rear", "Dodge", "Sticky tyre for drag cars", 350, 50, 17), Tyre("315/50R-17", "Dodge", "Sticky tyre for drag cars", 350, 50, 17),
                                Tyre("245/55R-18/front", "Dodge", "Sticky tyre for drag cars", 245, 55, 18), Tyre("245/55R-18/front", "Dodge", "Sticky tyre for drag cars", 245, 55, 18),
                                Battery("customName", "Dodge", "Large fuelTank for drag cars", 50, "doggeBattery"),
                                600, 1937);

    Car lamborghiniHuracanSTO(FuelTank("customName", "Lamborghini", "Large fuelTank for race cars", 80),
                              Engine("customName", "Lamborghini", "Large fuelTank for race cars", 640),
                              Tyre("245/30 R20 Front", "Lamborghini", "Sticky tyre for race cars", 245, 30, 20), Tyre("245/30 R20 Front", "Lamborghini", "Sticky tyre for race cars", 245, 30, 20),
                              Tyre("305 / 30 R20 Rear", "Lamborghini", "Sticky tyre for race cars", 305, 30, 20), Tyre("305 / 30 R20 Rear", "Lamborghini", "Sticky tyre for race cars", 305, 30, 20),
                              Battery("customName", "Audi", "Large fuelTank for drag cars", 55, "Audi battery"),
                              6000, 1337);

    Car *winner = dragRace(&dodgeChallengerDemon170, &lamborghiniHuracanSTO);

    if (winner != nullptr)
    {
        std::cout << "The winner is Car " << (winner == &dodgeChallengerDemon170 ? "Dodge Challenger Demon 170" : "Lamborghini Huracan STO") << std::endl;
    }
    else
    {
        std::cout << "No winner. Both cars are out of fuel." << std::endl;
    }
}

// Q&A
// how to reuser the operator<<