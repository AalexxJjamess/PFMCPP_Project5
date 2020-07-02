#include "Bike.h"

Bike::Bike() 
{ 
    currentGear = 1; 
}

Bike::~Bike()
{ 
    slowDown(speed); 
    std::cout << "~Bike" << std::endl;
}

void Bike::moveForwards(int howFar)
{
    distanceTravelled += howFar * speed;
}

void Bike::slowDown(int howMuch)
{
    speed -= howMuch;
}

void Bike::changeGearUp(int gearup = 1)
{
    currentGear += gearup;
    std::cout << "Going up a gear." << std::endl;
}
