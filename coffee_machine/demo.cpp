#include "machine.hpp"
#include <iostream>
#include <string>

int main(){
	std::cout << "Enter the coffee name: \n";
	std::string name;
	Machine *ob = new Machine(10,10,10);
	ob->addNewRecipe("latte", 1, 2, 3);
	while(1){
	std::cin>>name;
	ob->order(name);
	}		
}
