/*
Project 5: Part 1 / 4
 video Chapter 2 - Part 12

 Create a branch named Part1

Purpose:  This project continues developing Project3.
       you will learn how to take code from existing projects and migrate only what you need to new projects
       you will learn how to write code that doesn't leak as well as how to refactor. 

 Destructors
        
 0) move all of your implementations of all functions to OUTSIDE of the class. 
 
 1) Copy 3 of your user-defined types (the ones with constructors and for()/while() loops from Project 3) here
 2) add destructors
        make the destructors do something like print out the name of the class.

 3) add 2 new UDTs that use only the types you copied above as member variables.
 
 4) add 2 member functions that use your member variables to each of these new UDTs

 5) Add destructors to these 2 new types that do stuff.  
        maybe print out the name of the class being destructed, or call a member function of one of the members.  be creative
 
 6) copy over your main() from the end of Project3 and get it to compile with the types you copied over.
        remove any code in main() that uses types you didn't copy over.
 
 7) Instantiate your 2 UDT's from step 4) in the main() function at the bottom.
 
 8) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 
 */
#include<iostream>
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

//New UDT 5:

struct DJBusker
{
    Bike djBuskerBike;
    Turntable djRig;
    
    DJBusker();
    ~DJBusker();
    void moveToNewSpot(int);
    void playRecord(bool);
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

/*
 MAKE SURE YOU ARE NOT ON THE MASTER BRANCH

 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 If you didn't already: 
    Make a pull request after you make your first commit
    pin the pull request link and this repl.it link to our DM thread in a single message.

 send me a DM to review your pull request when the project is ready for review.

 Wait for my code review.
 */

#include <iostream>
int main()
{

//======================================================

    Band myBand;
    Band yourBand;
    myBand.playSong();
    std::cout << yourBand.numberOfSongs << std::endl;;

//======================================================

    Bike roadbike;
    Bike mountain;
    roadbike.changeGearUp(1);
    mountain.moveForwards(10);

//======================================================

    Turntable technics;
    technics.lowerStylus();
    technics.switchlightOn();

//======================================================

    GuitarBusker townes;
    DJBusker shadow;


    std::cout << "good to go!" << std::endl;
}
