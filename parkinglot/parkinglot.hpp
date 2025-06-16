#ifndef PARKINGLOT_HPP
#define PARKINGLOT_HPP

#include "spot.hpp"
#include <vector>
#include <map>
#include <string>

class ParkingLot{
private:
    std::vector<Spot*> spots;
    std::map<std::string, Spot*> plateToSpot;
    int capacity;
    int available;

public:
    ParkingLot(int numSmall, int numMedium, int numLarge);
    ~ParkingLot();

    int getCapacity() const;
    int getAvailableSpots() const;

    bool parkVehicle(Vehicle* vehicle);
    Vehicle* removeVehicle(const std::string &numberPlate);
    Spot* findVehicle(const std::string &numberPlate) const;

    void displayInfo() const;
    void displayOccupancy() const;

private:
    Spot* findAvailableSpot(const Vehicle* vehicle) const;
};  

#endif
