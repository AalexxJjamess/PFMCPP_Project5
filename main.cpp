/*
Project 5: Part 2 / 4
 video: Chapter 3 Part 1

Create a branch named Part2

 The 'this' keyword
 
 The purpose of this project part is to show you how accessing member variables of objects INSIDE member functions is very similar to accessing member variables of objects OUTSIDE of member functions, via 'this->' and via the '.' operator.
 This project part will break the D.R.Y. rule, but that is fine for the purpose of this project part.
 
 
 1) if you don't have any std::cout statements in main() that access member variables of your U.D.Ts
         write some.
    You can copy some from your Project3's main() if needed.
 
 2) For each std::cout statement in main() that accessed member variables of your types or printed out the results of your member function calls,
        a) write a member function that prints the same thing out, but uses the proper techniques inside the member functions to access the same member variables/functions.
        b) be explicit with your use of 'this->' in those member functions so we see how you're accessing/calling those member variables and functions *inside*
        c) call that member function after your std::cout statement in main.
        d) you should see 2 (almost) identical messages in the program output for each member function you add:
            one for the std::cout line, and one for the member function's output
 
 
 3) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 */

/*
 example:
 */
#include <iostream>
namespace Example
{
    //a User-Defined Type
    struct MyFoo
    {
        MyFoo() { std::cout << "creating MyFoo" << std::endl; }
        ~MyFoo() { std::cout << "destroying MyFoo" << std::endl; }
		
		// 2a) the member function whose function body is almost identical to the std::cout statement in main.
        void memberFunc() 
		{ 
            // 2b) explicitly using 'this' inside this member function.
			std::cout << "MyFoo returnValue(): " << this->returnValue() << " and MyFoo memberVariable: " << this->memberVariable << std::endl; 
		}  
		
        int returnValue() { return 3; }
        float memberVariable = 3.14f;
    };
    
    int main()
    {
        //an instance of the User-Defined Type named mf
        MyFoo mf;
		
        // 1) a std::cout statement that uses mf's member variables
        std::cout << "mf returnValue(): " << mf.returnValue() << " and mf memberVariable: " << mf.memberVariable << std::endl; 
		
        // 2c) calling mf's member function.  the member function's body is almost identical to the cout statement above.
        mf.memberFunc();
        return 0;
    }
}

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
    void saySetlist();
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
    Example::main();
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
    townes.oneManBand.songNames = "Lungs, Pancho & Lefty";
    shadow.djRig.spinPlatter(45);


    std::cout << "Turntable speed at: " << shadow.djRig.speed << std::endl;
    std::cout << "Busker Setlist: " << townes.oneManBand.songNames << std::endl;

    shadow.sayTurntableSpeed();
    townes.saySetlist();
    

    std::cout << "good to go!" << std::endl;
}
