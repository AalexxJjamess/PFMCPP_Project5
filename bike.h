
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
