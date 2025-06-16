#ifndef SPOT_HPP
#define SPOT_HPP

#include "vehicle.hpp"

enum class SpotType{
    SMALL,
    MEDIUM,
    LARGE
};

class Spot {
private:
    int spotNumber;
    bool occupied;
    SpotType type;
    Vehicle *vehicle;

public:
    Spot(int spotNumber, SpotType type);

    int getSpotNumber() const;
    bool isOccupied() const;
    SpotType getSpotType() const;
    Vehicle* getVehicle() const;
    
    bool canFit(const Vehicle* vehicle) const;
    bool parkVehicle(Vehicle* vehicle);
    Vehicle* removeVehicle();
    void displayInfo() const;
};

#endif