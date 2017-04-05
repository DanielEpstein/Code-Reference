#include <iostream>
#include <string>
#include <vector>
#include <fstream>

#include "input.h"
#include "types.h"
#include "diskio.h"
#include "sort.h"
#include "display.h"

using namespace std;

int main()
{
	double myMoney;
	bool exit = false;

	cout << " Please enter how much money you have: ";
	cin >> myMoney;
	
	vector<Product> myProducts = LoadProducts("Products.txt");

	MenuState myMenu = MainMenu;
	while (!exit)
	{
		switch (myMenu)
		{
			case MainMenu:
				myMenu = GetMenuSelection(myMoney);
				break;

			case AddProduct:
				myProducts.push_back(CreateProduct());
				SaveProducts(myProducts, "Products.txt");
				myMenu = MainMenu;
				break;

			case DeleteProduct:
				if (myProducts.size() != 0)
				{
					myProducts.erase(myProducts.begin() + GetVectorPosition());
					SaveProducts(myProducts, "Products.txt");
				}
				else
				{
					cout << " Error: No Products";
				}
				myMenu = MainMenu;
				break;

			case SortProducts:
				myProducts = BubbleSwap(myProducts);
				SaveProducts(myProducts, "Products.txt");
				myMenu = MainMenu;
				break;

			case PurchaseProduct:
				myMoney = BuyProduct(myProducts, GetInt(" Which product do you want to buy"), myMoney);
				myMenu = MainMenu;
				break;

			case DisplayProducts:
				ShowProducts(myProducts);
				myMenu = MainMenu;
				break;

			case ExitProgram:
				exit = true;
				break;
		}
	}
	return 0;
}