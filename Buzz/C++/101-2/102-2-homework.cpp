// Ask the user how much money they have.
// Present a list of products to the user.
// There must be at least 4 products listed(name and prices).
// The user will select an item from the product list or they will indicate that they want to exit.
// The  program will inform the user what item they purchased and how much money they have left.
// The program will continue to execute until the user doesn't have enough money to purchase anything, or decides to exit.
// Remember to allow for pennies / cents / etc.in prices.
// 
// Allowed to use :
// - while loops
// - if statements
// - cin / cout
// - arrays(if you want)
// - any primitive data type
// - variables

#include <iostream>
using namespace std;

int main()
{
	cout << " How much money do you have? ";
	double myMoney;
	cin >> myMoney;

	bool exit = false;
	double prices[4] = { 30, 40, 70, 60 };
	int input;
	while (!exit)
	{
		cout << "\n\n 1 - Ford Car $" << prices[0] << "\n 2 - Holden Car $" << prices[1] << "\n 3 - BMW Car $" << prices[2] << "\n 4 - Subaru Car $" << prices[3] << "\n 0 - Exit\n";
		cout << "\n Your Money: $" << myMoney << "\n Please make a selection: ";
		cin >> input;

		if (input == (int)0)
		{
			exit = true;
		}
		else if (input == (int)1)
		{
			if (myMoney >= prices[0])
			{
				myMoney -= prices[0];
				cout << "\n You purchased a Ford Car for $" << prices[0];
			}
			else
			{
				cout << "\n You do not have enough money!";
				cin.clear();
				cin.ignore();
			}
		}
		else if (input == (int)2)
		{
			if (myMoney >= prices[1])
			{
				myMoney -= prices[1];
				cout << "\n You purchased a Holden Car for $" << prices[1];
			}
			else
			{
				cout << "\n You do not have enough money!";
				cin.clear();
				cin.ignore();
			}
		}
		else if (input == (int)3)
		{
			if (myMoney >= prices[2])
			{
				myMoney -= prices[2];
				cout << "\n You purchased a BMW Car for $" << prices[2];
			}
			else
			{
				cout << "\n You do not have enough money!";
				cin.clear();
				cin.ignore();
			}
		}
		else if (input == (int)4)
		{
			if (myMoney >= prices[3])
			{
				myMoney -= prices[3];
				cout << "\n You purchased a Subaru Car for $" << prices[3];
			}
			else
			{
				cout << "\n You do not have enough money!";
				cin.clear();
				cin.ignore();
			}
		}
		else
		{
			cout << "\n Invalid Input, Please try again";
			cin.clear();
			cin.ignore();
		}
	}
	return 0;
}