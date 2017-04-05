// submit a modified version of last week's vending machine.
// The functionality of the program should remain the same.
// However; the code need to be refactored into individual.cpp files,
// header files and functions as demonstrated in class.

#include <iostream>
#include <string>
#include <sstream>
#include "input.h"

using namespace std;
double Selection(int selection);

double myMoney;
string names[4];
double prices[4];
int aSize = 4;

int main()
{
	// create item and price lists
	stringstream ss;
	for (int i = 0; i < aSize; i++)
	{
		ss << " Please enter name for item " << i + 1;
		names[i] = GetString(ss.str());
		ss = stringstream();

		ss << " Please enter a price for item " << i + 1;
		prices[i] = GetInt(ss.str());
		ss = stringstream();
	}

	// sort the item and price lists
	double priceTemp;
	string nameTemp;
	bool bsHappened;
	while (true)
	{
		bsHappened = false;
		for (int i = 0; i < aSize - 1; i++)
		{
			if (prices[i] > prices[i + 1])
			{
				bsHappened = true;

				// back up the bottom item in array
				priceTemp = prices[i];
				nameTemp = names[i];

				// set the bottom from the top
				prices[i] = prices[i + 1];
				names[i] = names[i + 1];

				// set the top from the backed up bottom
				prices[i + 1] = priceTemp;
				names[i + 1] = nameTemp;
			}
		}
		if (!bsHappened)
		{
			break;
		}
	}
	 
	// set how much money you have
	cout << " Please enter how much money you have: ";
	cin >> myMoney;

	// present menu with choses
	int selection;
	while (true)
	{
		cout << " 0 - Exit\n";
		for (int i = 1; i <= aSize; i++)
		{
			cout << " " << i << " - " << names[i - 1] << " ($" << prices[i - 1] << ")\n";
		}

		cout << " Account: $" << myMoney << "\n";
		selection = GetInt("Please make a selection");

		if (selection == 0)
		{
			break;
		}
		else if (selection == 1)
		{
			myMoney -= Selection(selection);
		}
		else if (selection == 2)
		{
			myMoney -= Selection(selection);
		}
		else if (selection == 3)
		{
			myMoney -= Selection(selection);
		}
		else if (selection == 4)
		{
			myMoney -= Selection(selection);
		}
		else
		{
			cout << " Invalid selection\n";
		}
		cin.clear();
	}
	return 0;
}

double Selection(int selection)
{
	if (myMoney >= prices[selection - 1])
	{
		cout << " You have purchased a " << names[selection - 1] << " for " << prices[selection - 1] << std::endl;
		return prices[selection - 1];
	}
	else
	{
		cout << " You dont have enough money!\n";
		return 0;
	}
}