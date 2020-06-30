#include "djbusker.h"

DJBusker::DJBusker()
{
    std::cout << "New DJ" << std::endl;
}
DJBusker::~DJBusker()
{
    std::cout << "~DJBusker" << std::endl;
}

void DJBusker::playRecord(bool single)
{
    djRig.lowerStylus();
    if (single)
    {
        djRig.spinPlatter(45);
    }
    else
    {
        djRig.spinPlatter(33);
    }
}

void DJBusker::moveToNewSpot(int howFar)
{
    for (int i = 0; i < howFar; ++i)
    {
        djBuskerBike.distanceTravelled++;
    }
}

void DJBusker::sayTurntableSpeed()
{
    std::cout << "Turntable speed at: " << this->djRig.speed << std::endl;
}
