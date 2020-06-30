
struct BandWrapper
{
    BandWrapper(Band* ptr);
    ~BandWrapper();

    Band* pointerToBand;
};

struct TurntableWrapper
{
    TurntableWrapper(Turntable* ptr);
    ~TurntableWrapper();

    Turntable* pointerToTurntable;
};

struct BikeWrapper
{
    BikeWrapper(Bike* ptr);
    ~BikeWrapper();
    
    Bike* pointerToBike;
};

struct GuitarBuskerWrapper
{
    GuitarBuskerWrapper(GuitarBusker* ptr);
    ~GuitarBuskerWrapper();

    GuitarBusker* pointerToGuitarBusker;
};

struct DJBuskerWrapper
{
    DJBuskerWrapper(DJBusker* ptr);
    ~DJBuskerWrapper();
    
    DJBusker* pointerToDJBusker;
};
