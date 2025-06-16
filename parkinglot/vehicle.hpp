#ifndef VEHICLE_HPP
#define VEHICLE_HPP

#include <string>

enum class VehicleType {
    BIKE,
    CAR,
    BUS
};

class Vehicle {
private:
    std::string numberPlate;
    VehicleType type;
    
public:
    Vehicle(std::string numberPlate, VehicleType type);

    std::string getNumberPlate() const;
    VehicleType getType() const;
    void displayInfo() const;
};

#endif
