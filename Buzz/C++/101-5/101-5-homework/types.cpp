#include <string>

using namespace std;

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