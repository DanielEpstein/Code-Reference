#include <iostream>
#include <string>


#include "input.h"


using namespace std;



void input()
{
	const int aSize = 4;
	string names[aSize];
	double prices[aSize];

	for (int i = 0; i < aSize; i++)
	{
		cout << " Please enter name for item " << i + 1 << ": ";
		getline(cin, names[i]);
		cout << " Please enter a price for item " << i + 1 << ": ";
		cin >> prices[i];
		cin.ignore();
	}






	void BubbleSort()
	{
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
	}

	cout << " Please enter how much money you have: ";
	double myMoney = 0;
	cin >> myMoney;
}



