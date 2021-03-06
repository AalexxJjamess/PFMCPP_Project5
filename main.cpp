/*
 Project 5: Part 4 / 4
 video: Chapter 3 Part 7

 Create a branch named Part4
 
 Don't #include what you don't use
 
 1) Your task is to refactor your Chapter 3 Part 4 task into separate source and header files.
         Add files via the pane on the left.
 
 2) Put all of your declarations for each class in .h files
         One header file per class ( i.e. Raider.h for a class named "Raider" )
 
 3) Put all of your implementations in .cpp files.
         one cpp file per class ( i.e. Raider.cpp for a class named "Raider" )
 
 4) Put all of your Wrapper classes in a single Wrappers.h file
         if you implemented your wrapper class functions in-class, you'll need to move them to Wrappers.cpp
 
 5) NO IN-CLASS IMPLEMENTATION ALLOWED.
         the only exception is the existing Atomic.h and LeakedObjectDetector.h
 
 6) for every .cpp file you have to make, insert it into the .replit file after 'main.cpp'.  Don't forget the spaces between file names.
 If you need help with this step, send me a DM.
 
 7) click the [run] button.  Clear up any errors or warnings as best you can.
 
 Remember, your Chapter 3 Part 4 task worked when it was all in one file. so you shouldn't need to edit any of it.  
         just split it up into source files and provide the appropriate #include directives.
 */

#include <iostream>
#include "LeakedObjectDetector.h"

#include "Band.h"
#include "Bike.h"
#include "Turntable.h"
#include "DJBusker.h"
#include "GuitarBusker.h"
#include "Wrappers.h"


int main()
{
    
//======================================================

    BandWrapper myBand( new Band());
    BandWrapper yourBand( new Band());
    myBand.pointerToBand->playSong();
    std::cout << yourBand.pointerToBand->numberOfSongs;
    

//======================================================

    BikeWrapper roadbike( new Bike());
    BikeWrapper mountain( new Bike());
    roadbike.pointerToBike->changeGearUp(1);
    mountain.pointerToBike->moveForwards(10);

//======================================================

    TurntableWrapper technics(new Turntable());
    technics.pointerToTurntable->lowerStylus();
    technics.pointerToTurntable->switchlightOn();

//======================================================

    DJBuskerWrapper shadow(new DJBusker());
    GuitarBuskerWrapper townes(new GuitarBusker());
    townes.pointerToGuitarBusker->oneManBand.songNames = "Lungs, Pancho & Lefty";
    townes.pointerToGuitarBusker->playSet();
    shadow.pointerToDJBusker->djRig.spinPlatter(45);

    std::cout << "Turntable speed at: " << shadow.pointerToDJBusker->djRig.speed << std::endl;
    townes.pointerToGuitarBusker->saySetlist();
    shadow.pointerToDJBusker->sayTurntableSpeed();
    
    std::cout << "good to go!" << std::endl;
}
