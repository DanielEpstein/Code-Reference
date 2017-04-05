#ifndef TYPES_H
#define TYPES_H

#include <string>
using std::string;

struct Product
{
	string Name;
	double Price;
	string Description;
};

enum MenuState
{
	MainMenu,
	AddProduct,
	SortProducts,
	DeleteProduct,
	PurchaseProduct,
	DisplayProducts,
	ExitProgram
};

#endif



