#include "band.h"

Band::Band() : currentSong(1)
{ 
    std::cout << "Setlist: " << songNames << std::endl;
}

Band::~Band() 
{ 
    std::cout << "~Band\n"; 
}

void Band::moveToNextSong()
{
    currentSong += 1;
}

void Band::playSong()
{
    playingSong = true;
    std::cout << "Playing song: "<< currentSong << std::endl;
    playingSong = false;
}
