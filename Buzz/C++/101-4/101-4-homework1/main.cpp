// submit a modified version of last week's vending machine.
// The functionality of the program should remain the same.
// However; the code need to be refactored into individual.cpp files, 
// header files and functions as demonstrated in class.

#include <iostream>
#include <string>

#include "input.h"
#include "menu.h"

using namespace std;

struct data
{
	const int aSize;
	std::string names[aSize];
	double prices[aSize];
	double myMoney;
};


int main()
{

	input(aSize, names, prices);


	// cin.ignore();
	// cin.get();
	return 0;
}