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
