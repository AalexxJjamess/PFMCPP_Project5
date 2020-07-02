#pragma once
#include <iostream>
#include <string>
#include "LeakedObjectDetector.h"

struct Band;
struct Bike;
struct Turntable;
struct DJBusker;
struct GuitarBusker;

struct BandWrapper
{
    BandWrapper(Band*);
    ~BandWrapper();
    Band* pointerToBand;
};

struct TurntableWrapper
{
    TurntableWrapper(Turntable*);
    ~TurntableWrapper();
    Turntable* pointerToTurntable;
};

struct BikeWrapper
{
    BikeWrapper(Bike*);
    ~BikeWrapper();
    Bike* pointerToBike;
};

struct GuitarBuskerWrapper
{
    GuitarBuskerWrapper(GuitarBusker*);
    ~GuitarBuskerWrapper();
    GuitarBusker* pointerToGuitarBusker;
};

struct DJBuskerWrapper
{
    DJBuskerWrapper(DJBusker*);
    ~DJBuskerWrapper();
    DJBusker* pointerToDJBusker;
};

