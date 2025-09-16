#include "machine.hpp"
#include "coffee.hpp"
#include <iostream>

Machine::Machine(int milk, int water, int coffee){
	curr_milk = milk;
	curr_water = water;
	curr_coffee = coffee;
}
void Machine::addNewRecipe(std::string name, int milk, int coffee, int water){
	Coffee ob(milk, coffee, water);
	map_coffee[name] = ob;
}

bool Machine::check(Coffee ob){
	if(curr_milk >= ob.milk and curr_water >= ob.water and curr_coffee >= ob.coffee) return true;
	return false;
}

void Machine::order(std::string name){
	if(map_coffee.find(name) == map_coffee.end()){
		std::cout << "Not Available!\n";
		return;
	}
	Coffee ob = map_coffee[name];
	if(check(ob)){
		curr_milk -= ob.milk;
		curr_water -= ob.water;
		curr_coffee -= ob.coffee; 
		std::cout<<"Success! \n";
	}
	else std::cout << "Failed! \n";
}
