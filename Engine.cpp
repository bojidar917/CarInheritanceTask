#include "Engine.h"
#include "CarPart.cpp"

Engine::Engine()
{
}

Engine::Engine(const char *id, const char *manifacturerName, const char *description, const int hp)
    : CarPart(id, manifacturerName, description)
{
    setHp(hp);
}

Engine::Engine(const Engine &other)
    : CarPart(other)
{
    this->hp = hp;
}

Engine &Engine::operator=(const Engine &other)
{
    if (this != &other)
    {
        CarPart::operator=(other);
        this->hp = other.hp;
    }

    return *this;
}

std::ostream &Engine::operator<<(std::ostream &os) const
{
    //(<id>) by <manufacturer> – <description> – <horsepower> hp

    os << "( " << getId() << ")"
       << "by" << getManifacturerName() << "-" << getDesctiption() << "-" << this->hp << " hp";
    return os;
}

void Engine::setHp(int hp)
{
    if (hp < 0)
        hp = 0;
    this->hp = hp;
}
