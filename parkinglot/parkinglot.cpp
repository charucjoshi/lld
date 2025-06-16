#include "parkinglot.hpp"
#include <iostream>

ParkingLot::ParkingLot(int numSmall, int numMedium, int numLarge) : capacity(numSmall + numMedium + numLarge), available(capacity) {

        int spotNumber = 1;
        for(int i = 0; i < numSmall; ++i){
            spots.push_back(new Spot(spotNumber, SpotType::SMALL));
            spotNumber++;
        }

        for(int i = 0; i < numMedium; ++i){
            spots.push_back(new Spot(spotNumber, SpotType::MEDIUM));
            spotNumber++;
        }

        for(int i = 0; i < numLarge; ++i) {
            spots.push_back(new Spot(spotNumber, SpotType::LARGE));
            spotNumber++;
        }
}

ParkingLot::~ParkingLot() {
    for(auto spot : spots) {
        delete spot;
    }
}

int ParkingLot::getCapacity() const {return capacity; }
int ParkingLot::getAvailableSpots() const { return available; }

bool ParkingLot::parkVehicle(Vehicle* vehicle) {
    if(!vehicle) return false;

    if(plateToSpot.find(vehicle->getNumberPlate()) != plateToSpot.end()) return false;

    Spot *spot = findAvailableSpot(vehicle);
    if(!spot) return false;
    
    if(spot->parkVehicle(vehicle)){
        plateToSpot[vehicle->getNumberPlate()] = spot;
        available--;
        return true;
    }

    return false;
}

Vehicle* ParkingLot::removeVehicle(const std::string &numberPlate){
    if(plateToSpot.find(numberPlate) == plateToSpot.end()) return nullptr;

    Spot* spot = plateToSpot[numberPlate];
    Vehicle* vehicle = spot->removeVehicle();
    if(vehicle){
        plateToSpot.erase(numberPlate);
        available++;
    }
    return vehicle;
}

Spot* ParkingLot::findVehicle(const std::string &numberPlate) const{
    auto it = plateToSpot.find(numberPlate);
    if(it == plateToSpot.end()) return nullptr;
    return it->second;
}

Spot* ParkingLot::findAvailableSpot(const Vehicle* vehicle) const {
    for(auto spot : spots){
        if(spot->isOccupied() == false and spot->canFit(vehicle)) {
            return spot;
        }
    }
    return nullptr;
}

void ParkingLot::displayOccupancy() const {
    for(auto spot : spots){
        spot->displayInfo();
    }
}
void ParkingLot::displayInfo() const {
    std::cout << "Capacity : " << capacity << std::endl;
    std::cout << "Available Spots : " << available << std::endl;
}