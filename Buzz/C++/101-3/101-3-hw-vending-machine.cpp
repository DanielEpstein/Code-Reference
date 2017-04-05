// Modify vending machine
// 
// At the beginning of the program, allow the user to enter 4 products(name and price).
// You do not need to support names with spaces in them(but you may if you wish) - and you still do not need to woryy about input validation.
// 
// The rest of the program will continue to hehave as before, except that products must
// be displayed to the user in ascending order of price(bubble sort).
// 
// No fuctions allow other than main!

#include <iostream>
#include <string>

using namespace std;

int main()
{
	double myMoney;
	string names[4];
	double prices[4];
	bool exit = false;
	int selection;
	int aSize = 4;
	double priceTemp;
	string nameTemp;
	bool bsHappened;

	for (int i = 0; i < aSize; i++)
	{
		cout << " Please enter name for item " << i + 1 << ": ";
		getline(cin, names[i]);
		cout << " Please enter a price for item " << i + 1 << ": ";
		cin >> prices[i];
		cin.ignore();
	}

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

	cout << " Please enter how much money you have: ";
	cin >> myMoney;


	while (!exit)
	{
		cout << " 0 - Exit\n";
		for (int i = 1; i <= aSize; i++)
		{
			cout << " " << i << " - " << names[i - 1] << " ($" << prices[i - 1] << ")\n";
		}

		cout << " Account: $" << myMoney << "\n Please make a selection: ";

		cin >> selection;
		
		if (selection == 0)
		{
			exit = true;
		}
		else if (selection == 1)
		{
			if (myMoney >= prices[selection - 1])
			{
				cout << " You have purchased a " << names[selection - 1] << " for " << prices[selection - 1] << std::endl;
				myMoney -= prices[selection - 1];
			}
			else
			{
				cout << " You dont have enough money!\n";
			}
		}
		else if (selection == 2)
		{
			if (myMoney >= prices[selection - 1])
			{
				cout << " You have purchased a " << names[selection - 1] << " for " << prices[selection - 1] << std::endl;
				myMoney -= prices[selection - 1];
			}
			else
			{
				cout << " You dont have enough money!\n";
			}
		}
		else if (selection == 3)
		{
			if (myMoney >= prices[selection - 1])
			{
				cout << " You have purchased a " << names[selection - 1] << " for " << prices[selection - 1] << std::endl;
				myMoney -= prices[selection - 1];
			}
			else
			{
				cout << " You dont have enough money!\n";
			}
		}
		else if (selection == 4)
		{
			if (myMoney >= prices[selection - 1])
			{
				cout << " You have purchased a " << names[selection - 1] << " for " << prices[selection - 1] << std::endl;
				myMoney -= prices[selection - 1];
			}
			else
			{
				cout << " You dont have enough money!\n";
			}
		}
		else
		{
			cout << " Invalid selection\n";
		}
		cin.clear();
	}

	// cin.ignore();
	// cin.get();
	return 0;
}