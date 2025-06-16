#include "vehicle.hpp"
#include <iostream>

Vehicle::Vehicle(std::string numberPlate, VehicleType type) : numberPlate(numberPlate), type(type) {}

std::string Vehicle::getNumberPlate() const {
    return numberPlate;
}

VehicleType Vehicle::getType() const {
    return type;
}

void Vehicle::displayInfo() const {
    std::cout << "Number Plate : " << numberPlate << std::endl;
    std::cout << "Type : ";
    switch(type){
        case VehicleType::BIKE : std::cout << "BIKE" << std::endl; break;
        case VehicleType::CAR : std::cout << "CAR" << std::endl; break;
        case VehicleType::BUS : std::cout << "BUS" << std::endl; break;
    }
}