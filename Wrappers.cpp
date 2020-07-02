#include "Wrappers.h"
#include "Turntable.h"
#include "Bike.h"
#include "Band.h"
#include "GuitarBusker.h"
#include "DJBusker.h"

BandWrapper::BandWrapper(Band* ptr) : pointerToBand(ptr) {}
BandWrapper::~BandWrapper()
{
    delete pointerToBand;
}

TurntableWrapper::TurntableWrapper(Turntable* ptr) : pointerToTurntable(ptr) {}
TurntableWrapper::~TurntableWrapper()
{
    delete pointerToTurntable;
}

BikeWrapper::BikeWrapper(Bike* ptr) : pointerToBike(ptr) {}
BikeWrapper::~BikeWrapper()
{
    delete pointerToBike;
}

GuitarBuskerWrapper::GuitarBuskerWrapper(GuitarBusker* ptr) : pointerToGuitarBusker(ptr) {}
GuitarBuskerWrapper::~GuitarBuskerWrapper()
{
    delete pointerToGuitarBusker;
}

DJBuskerWrapper::DJBuskerWrapper(DJBusker* ptr) : pointerToDJBusker(ptr) {}
DJBuskerWrapper::~DJBuskerWrapper()
{
    delete pointerToDJBusker;
}
