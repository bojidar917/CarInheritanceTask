#include "Tyre.h"
#include "CarPart.cpp"

Tyre::Tyre() : CarPart(), width(0), profile(0), size(0)
{
}

Tyre::Tyre(const char *id, const char *manifacturerName, const char *description, const int width, const int profile, const int size)
    : CarPart(id, manifacturerName, description)
{
}

Tyre::Tyre(const Tyre &other)
    : CarPart(other),
      width(other.width), profile(other.profile), size(other.size)
{
}

Tyre &Tyre::operator=(const Tyre &other)
{
    if (this != &other)
    {
        CarPart::operator=(other);
        this->width = other.width;
        this->profile = other.profile;
        this->size = other.size;
    }

    return *this;
}

std::ostream &Tyre::operator<<(std::ostream &os) const
{
    //(<id>) by <manufacturer> – <description> – <width>/<profile>R<rim size>

    os << "( " << getId() << ")"
       << "by" << getManifacturerName() << "-" << getDesctiption() << "-" << this->width << "/" << this->profile << "R" << this->size;
    return os;
}

void Tyre::setWidth(const int width)
{
    if (width >= 155 && width <= 365)
        this->width = width;
    else
        this->width = 0;
}

void Tyre::setProfile(const int profile)
{
    if (profile >= 30 && profile <= 80)
        this->profile = profile;
    else
        this->profile = 0;
}

void Tyre::setSize(const int size)
{
    if (size >= 13 && size <= 21)
        this->size = size;
    else
        this->size = 0;
}
