#include "CarPart.h"
#include <iostream>

class Tyre : public CarPart
{
public:
    Tyre();
    Tyre(const char *id, const char *manifacturerName, const char *description, const int width, const int profile, const int size);
    Tyre(const Tyre &other);
    Tyre &operator=(const Tyre &other);
    std::ostream &operator<<(std::ostream &os) const;

    int getWidth() const { return width; }
    int getProfile() const { return profile; }
    int getSize() const { return size; }

    void setWidth(const int width);
    void setProfile(const int profile);
    void setSize(const int size);

private:
    int width;
    int profile;
    int size;
};