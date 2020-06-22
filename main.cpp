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





#include<iostream>
#include "LeakedObjectDetector.h"

/*
 copied UDT 1:
 */

struct Band 
{
    int currentSong;
    bool playingSong = false;
    std::string songNames = "Cissy Strut, Everyday People, Alone Again Or";
    int numberOfSongs;

    Band();
    ~Band();
    void moveToNextSong();
    void playSong();

    JUCE_LEAK_DETECTOR(Band)
};

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



/*
 copied UDT 2:
 */
struct Turntable
{
    std::string cartType;
    char chassisMaterial;
    int armHeight;
    int speed;
    bool stylusOn = false;
    bool lightOn = false;
    Turntable();
    ~Turntable();

    void spinPlatter(int);
    void switchlightOn();
    void lowerStylus();

    JUCE_LEAK_DETECTOR(Turntable)
};

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


/*
 copied UDT 3:
 */
struct Bike
{
    int currentGear;
    char frameMaterial;
    float seatHeight;
    int distanceTravelled = 0;
    int speed = 1;
    
    Bike();
    ~Bike();
    void moveForwards(int);
    void slowDown(int);
    void changeGearUp(int);

    JUCE_LEAK_DETECTOR(Bike)
};

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

/*
 new UDT 4:
 with 2 member functions
 */



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

//New UDT 5: 2) For each std::cout statement in main() that accessed member variables of your types or printed out the results of your member function calls,
 //       a) write a member function that prints the same thing out, but uses the proper techniques inside the member functions to access the same member variables/functions.

struct DJBusker
{
    Bike djBuskerBike;
    Turntable djRig;
    
    DJBusker();
    ~DJBusker();
    void moveToNewSpot(int);
    void playRecord(bool);
    void sayTurntableSpeed();
    JUCE_LEAK_DETECTOR(DJBusker)
};

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

// WRAPPER CLASSES ============================================
struct BandWrapper
{
    BandWrapper(Band* ptr) : pointerToBand(ptr) {}
    ~BandWrapper()
    {
        delete pointerToBand;
    }

    Band* pointerToBand;

};

struct TurntableWrapper
{
    TurntableWrapper(Turntable* ptr) : pointerToTurntable(ptr) {}
    ~TurntableWrapper()
    {
        delete pointerToTurntable;
    }

    Turntable* pointerToTurntable;


};

struct BikeWrapper
{
    BikeWrapper(Bike* ptr) : pointerToBike(ptr) {}
    ~BikeWrapper()
    {
        delete pointerToBike;
    }

    Bike* pointerToBike;


};

struct GuitarBuskerWrapper
{
    GuitarBuskerWrapper(GuitarBusker* ptr) : pointerToGuitarBusker(ptr) {}
    ~GuitarBuskerWrapper()
    {
        delete pointerToGuitarBusker;
    }

    GuitarBusker* pointerToGuitarBusker;

};

struct DJBuskerWrapper
{
    DJBuskerWrapper(DJBusker* ptr) : pointerToDJBusker(ptr) {}
    ~DJBuskerWrapper()
    {
        delete pointerToDJBusker;
    }

    DJBusker* pointerToDJBusker;

};


/*
 MAKE SURE YOU ARE NOT ON THE MASTER BRANCH

 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 If you didn't already: 
    Make a pull request after you make your first commit
    pin the pull request link and this repl.it link to our DM thread in a single message.

 send me a DM to review your pull request when the project is ready for review.

 Wait for my code review.
 */


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
