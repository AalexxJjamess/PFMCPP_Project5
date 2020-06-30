#include "guitarbusker.h"

GuitarBusker::GuitarBusker()
{
    std::cout << "New Guitar Busker" << std::endl;
}
GuitarBusker::~GuitarBusker()
{
    std::cout << "~Busker" << std::endl;
}

void GuitarBusker::moveToNewSpot(int howFar)
{
    for (int i = 0; i < howFar; ++i)
    {
        buskerBike.distanceTravelled++;
    }
}

void GuitarBusker::playSet()
{   
    for (int i = 0; i < oneManBand.numberOfSongs; i++)
        oneManBand.playSong();
        oneManBand.currentSong++;
}

void GuitarBusker::saySetlist()
{
    std::cout << "Busker setlist: " << this->oneManBand.songNames << std::endl;
}
