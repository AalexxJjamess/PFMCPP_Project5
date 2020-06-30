
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
