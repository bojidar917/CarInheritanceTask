#include "CarPart.h"
#include <iostream>

class Engine : public CarPart
{
public:
    Engine();
    Engine(const char *id, const char *manifacturerName, const char *description, const int hp);
    Engine(const Engine &other);
    Engine &operator=(const Engine &other);
    Engine &operator<<(const Engine &other);
    std::ostream &operator<<(std::ostream &os) const;

    int getHp() const { return hp; }
    void setHp(int hp);

private:
    int hp;
};