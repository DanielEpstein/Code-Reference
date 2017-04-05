#include <iostream>
#include <string>
#include <vector>
#include "types.h"

using namespace std;

string promptsymbol = ": ";

int GetInt(string prompt)
{
	int temp;
	cout << prompt << promptsymbol;
	cin >> temp;
	cin.ignore();
	return temp;
}

int GetInt()
{
	return GetInt("Enter a int");
}

double GetDouble(string prompt)
{
	double temp;
	cout << prompt << promptsymbol;
	cin >> temp;
	cin.ignore();
	return temp;
}

double GetDouble()
{
	return GetInt("Enter a double");
}

string GetString(string prompt)
{
	string temp;
	cout << prompt << promptsymbol;
	getline(cin, temp);
	return temp;
}

string GetString()
{
	return GetString("Enter a string");
}

MenuState GetMenuSelection(double mymoney)
{
	cout << "\n [1] Main Menu\n [2] Add Product\n [3] Delete Product\n [4] Sort Products\n [5] Purchase Product\n [6] Display Products\n [7] Exit Program\n\n" << " Wallet: $" << mymoney << "\n";
	int input = GetInt(" Please make a selection");

	switch (input)
	{
	case 1: return MainMenu;
	case 2: return AddProduct;
	case 3: return DeleteProduct;
	case 4: return SortProducts;
	case 5: return PurchaseProduct;
	case 6: return DisplayProducts;
	case 7: return ExitProgram;
	}
	return MainMenu;
}

Product CreateProduct()
{
	Product tempProduct;

	tempProduct.Name = GetString(" Please enter a name");
	tempProduct.Price = GetDouble(" Please enter a price");
	tempProduct.Description = GetString(" Please enter a description");
	return tempProduct;
}

int GetVectorPosition()
{
	return GetInt(" Please enter an int");
}

double BuyProduct(vector<Product> products, int vectorpos, double mymoney)
{
	if (mymoney >= products[vectorpos].Price)
	{
		cout << " You have purchased a " << products[vectorpos].Name << " for " << products[vectorpos].Price << std::endl;
		return mymoney - products[vectorpos].Price;
	}
	else
	{
		cout << " You dont have enough money!\n";
		return mymoney;
	}
}