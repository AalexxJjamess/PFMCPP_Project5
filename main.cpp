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
    int numberOfMembers;
    int totalTourDistance = 0;

    Band();
    ~Band();
    void moveToNextSong();
    void playSong();
    void goToGig(int);
};

Band::Band() : currentSong(0){}
Band::~Band() { std::cout << "Band\n"; }


void Band::moveToNextSong()
{
    currentSong += 1;
}

void Band::playSong()
{
    playingSong = true;
    std::cout << "Playing: "<< songNames << std::endl;;
}

void Band::goToGig(int howFar = 10)
{
    totalTourDistance += howFar;
}

/*
 copied UDT 2:
 */
struct InstrumentCluster
{
    int speed;
    int miles;
    int fuel;
    int time;
    int RPM;

    InstrumentCluster();
    ~InstrumentCluster();
    int showSpeed();
    int showRPM();
    int showMiles();

};

InstrumentCluster::InstrumentCluster() : speed(0), miles(0), fuel(0), time(0), RPM(0){}
InstrumentCluster::~InstrumentCluster() { std::cout << "InstrumentCluster\n"; }

int InstrumentCluster::showSpeed()
{
    return speed;
}

int InstrumentCluster::showRPM()
{
    return RPM;
}

int InstrumentCluster::showMiles()
{
    return miles;
}
/*
 copied UDT 3:
 */
 struct Bike
{
    int currentGear;
    char frameMaterial;
    float seatHeight;
    int distanceTravelled;
    int speed = 1;
    
    Bike();
    ~Bike();
    void moveForwards(int);
    void slowDown(int);
    void changeGearUp(int);
};

Bike::Bike() { currentGear = 1; }

Bike::~Bike() { std::cout << "Bike\n"; }

void Bike::moveForwards(int howFar)
{
    distanceTravelled += howFar * speed;
}

void Bike::slowDown(int howMuch = -10)
{
    speed += howMuch;
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
 struct Handlebars
{
    int clutch = 0;
    int steeringAngle;
    int headLights;
    int acceleration;
    
    Handlebars();
    ~Handlebars();

    void clutchUp();
    void steer(int);
    void lightsUp(int);
    
};

Handlebars::Handlebars() : clutch(0), steeringAngle(0), headLights(0), acceleration(0){}
Handlebars::~Handlebars() { std::cout << "Handlebars\n"; }

void Handlebars::clutchUp()
{
     while (clutch < 101) 
     {
        if (clutch == 100)
        {
            std::cout << "The clutch is now at 100%" << std::endl;
        }
        ++clutch;
     }

}

void Handlebars::steer(int angleChange = 20)
{
    steeringAngle += angleChange;
}

void Handlebars::lightsUp(int howMuch)
{
    headLights += howMuch;
}

/*
 new UDT 5:
 with 2 member functions
 */
 struct Engine
{
    struct Cyclinders
    {
        int cc;
        int strokes;    
    };

    float fuelPerMile;
    int fuelType;
    int coolingType;
    int noise;
    int temperature;
    int RPM;

    Engine();
    ~Engine();
    void increaseRPM(int);
    void makeNoise(int);
    void heatUp(int);
};

Engine::Engine() { noise = fuelType = RPM = 0; }
Engine::~Engine() { std::cout << "Engine\n"; }

void Engine::increaseRPM(int howMuch)
{
    RPM += howMuch;
}

void Engine::makeNoise(int volume)
{
    noise += volume;
}

void Engine::heatUp(int temp)
{
    temperature += temp;
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
    std::cout << "good to go!" << std::endl;
}
