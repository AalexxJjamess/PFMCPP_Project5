
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
