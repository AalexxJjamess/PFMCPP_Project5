#include "Turntable.h"

Turntable::Turntable()
{
    speed = 0;
    armHeight = 100;
}

Turntable::~Turntable()
{
    std::cout << "~Turntable" << std::endl;
}

void Turntable::spinPlatter(int RPM)
{
    speed = RPM;
}

void Turntable::switchlightOn()
{
    lightOn = true;
}

void Turntable::lowerStylus()
{
    stylusOn = true;
    for (int i = armHeight; i == 0; --i)
    {
        armHeight = i;
    }
}
