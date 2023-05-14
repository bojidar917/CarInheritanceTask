#include "Battery.h"
#include "CarPart.cpp"
#include <cstring>

Battery::Battery()
{
}

Battery::Battery(const char *id, const char *manifacturerName, const char *description, const int capacity, const char *batteryId)
    : CarPart(id, manifacturerName, description)
{
    setCapacity(capacity);
    strcpy(this->batteryId, batteryId);
}

Battery::Battery(const Battery &other)
    : CarPart(other)
{
    this->capacity = other.capacity;
    strcpy(this->batteryId, other.batteryId);
}

Battery &Battery::operator=(const Battery &other)
{
    if (this != &other)
    {
        CarPart::operator=(other);
        this->capacity = other.capacity;
        strcpy(this->batteryId, other.batteryId);
    }

    return *this;
}

std::ostream &Battery::operator<<(std::ostream &os) const
{
    //(<id>) by <manufacturer> – <description> – <amp hours> Ah

    os << "( " << getId() << ")"
       << "by" << getManifacturerName() << "-" << getDesctiption() << "-" << this->capacity << " Ah";
    return os;
}

void Battery::setCapacity(int capacity)
{
    if (capacity < 0)
        capacity = 0;
    this->capacity = capacity;
}
