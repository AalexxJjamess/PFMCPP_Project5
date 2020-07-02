#pragma once
#include "LeakedObjectDetector.h"
#include "Bike.h"
#include "Band.h"
struct GuitarBusker
{
    Band oneManBand;
    Bike buskerBike;

    GuitarBusker();
    ~GuitarBusker();
    void moveToNewSpot(int);
    void playSet();
    void saySetlist();
    JUCE_LEAK_DETECTOR(GuitarBusker)
};
