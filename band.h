
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
