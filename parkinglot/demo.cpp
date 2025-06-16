#include "parkinglot.hpp"
#include <iostream>

int main(){
    ParkingLot lot(2,3,2);
    std::cout << "Initial Parking Lot Status: " << std::endl;
    lot.displayInfo();

     // Create vehicles
     Vehicle* car1 = new Vehicle("CAR001", VehicleType::CAR);
     Vehicle* car2 = new Vehicle("CAR002", VehicleType::CAR);
     Vehicle* bike = new Vehicle("BIKE001", VehicleType::BIKE);
     Vehicle* bus = new Vehicle("BUS001", VehicleType::BUS);

    // Park vehicles
    std::cout << "\nParking vehicles..." << std::endl;
    
    if (lot.parkVehicle(car1)) {
        std::cout << "Parked successfully: ";
        car1->displayInfo();
    }

    if (lot.parkVehicle(bike)) {
        std::cout << "Parked successfully: ";
        bike->displayInfo();
    }
    
    if (lot.parkVehicle(bus)) {
        std::cout << "Parked successfully: ";
        bus->displayInfo();
    }
    
    // Display current status
    lot.displayInfo();
    lot.displayOccupancy();
    
    // Remove a vehicle
    std::cout << "\nRemoving vehicle CAR001..." << std::endl;
    Vehicle* removed = lot.removeVehicle("CAR001");
    if (removed) {
        std::cout << "Removed successfully: ";
        removed->displayInfo();
        delete removed;
    }
    
    // Try to park another car
    if (lot.parkVehicle(car2)) {
        std::cout << "Parked successfully: ";
        car2->displayInfo();
    }
    
    // Final status
    std::cout << "\nFinal parking lot status:" << std::endl;
    lot.displayInfo();
    lot.displayOccupancy();
    
    // Cleanup remaining vehicles
    delete car2;
    delete bike;
    delete bus;

    return 0;
}