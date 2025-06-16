#include "spot.hpp"
#include <iostream>

Spot::Spot(int spotNumber, SpotType type) : spotNumber(spotNumber), type(type), occupied(false) {}

int Spot::getSpotNumber() const { return spotNumber ;}
bool Spot::isOccupied() const { return occupied; }
SpotType Spot::getSpotType() const { return type; }
Vehicle* Spot::getVehicle() const { return vehicle; }

bool Spot::canFit(const Vehicle *vehicle) const {
    if(!vehicle) return false;

    switch(vehicle->getType()) {
        case VehicleType::BIKE: return true;
        case VehicleType::CAR : return (type != SpotType::SMALL);
        case VehicleType::BUS : return (type == SpotType::LARGE);
    }

    return false;
}

bool Spot::parkVehicle(Vehicle *vehicle) {
    if(occupied || canFit(vehicle) == false) return false;
    occupied = true;
    this->vehicle = vehicle;
    return true;
}

Vehicle* Spot::removeVehicle() {
    if(!vehicle || !occupied) return nullptr;
    occupied = false;
    Vehicle* removedVehicle = vehicle;
    vehicle = nullptr;
    return removedVehicle;
}

void Spot::displayInfo() const {
    std::cout << "Spot Number : " << spotNumber << std::endl;
    std::cout << "Type : ";
    switch(type){
        case SpotType::SMALL : std::cout << "SMALL\n"; break;
        case SpotType::MEDIUM : std::cout << "MEDIUM\n"; break;
        case SpotType::LARGE : std::cout << "LARGE\n"; break;
    }
    std::cout << "Status : ";
    if(occupied){
        std::cout << "Occupied" << std::endl;
        vehicle->displayInfo();
    }
    else{
        std::cout << "Unoccupied" << std::endl;
    }
}


