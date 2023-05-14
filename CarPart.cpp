#include "CarPart.h"
#include <cstring>

CarPart::CarPart()
{
}

CarPart::CarPart(const char *id, const char *manifacturerName, const char *descrioption)
{
    strcpy(this->id, id);
    strcpy(this->manifacturerName, manifacturerName);
    strcpy(this->description, descrioption);
}

CarPart::CarPart(const CarPart &other)
    : id(other.id), manifacturerName(other.manifacturerName), description(other.description)
{
}

CarPart &CarPart::operator=(const CarPart &other)
{
    if (this != &other)
    {
        this->id = other.id;
        this->manifacturerName = other.manifacturerName;
        this->description = other.description;
    }

    return *this;
}

CarPart::~CarPart()
{
    destroy();
}

void CarPart::setDesctiption(const char *description)
{
    strcpy(this->description, description);
}

void CarPart::destroy()
{
    delete[] id;
    delete[] manifacturerName;
    delete[] description;
}
