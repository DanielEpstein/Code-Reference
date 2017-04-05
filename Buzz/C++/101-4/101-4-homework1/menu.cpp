#include <iostream>
#include <string>

using namespace std;



void menu()
{
	int selection;
	bool exit = false;


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
		cin.ignore();
	}
}


