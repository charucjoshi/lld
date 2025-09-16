#ifndef MACHINE_HPP
#define MACHINE_HPP

#include <map>
#include <string>
#include "coffee.hpp"
class Machine{
private:
	int curr_milk, curr_coffee, curr_water;
	std::map<std::string, Coffee> map_coffee;
public:
	Machine(int, int, int);
	void addNewRecipe(std::string, int, int, int);
	bool check(Coffee);
	void order(std::string);
};

#endif
