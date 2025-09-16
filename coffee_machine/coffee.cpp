#include "coffee.hpp"

Coffee::Coffee(){
	milk = 0;
	water = 0;
	coffee = 0;
}
Coffee::Coffee(int milk, int water, int coffee){
	this->milk = milk;
	this->water = water;
	this->coffee = coffee;
}
