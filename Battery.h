#include "CarPart.h"
#include <iostream>

class Battery : public CarPart
{
public:
    Battery();
    Battery(const char *id, const char *manifacturerName, const char *description, const int capacity, const char *batteryId);
    Battery(const Battery &other);
    Battery &operator=(const Battery &other);
    std::ostream &operator<<(std::ostream &os) const;

    int getCapacity() const { return capacity; }
    char const *getBatteryId() const { return batteryId; }

private:
    int capacity;
    char batteryId[15];

    void setCapacity(int capacity);
};