#include <string>

using namespace std;

template <int MS>
struct menu
{
	static const int menusize = MS;
	string names[menusize];
	double prices[menusize];
};


menu<4> bubbleswap(menu<4> mymenu)
{
	bool bsHappened;
	double priceTemp;
	string nameTemp;

	while (true)
	{
		bsHappened = false;
		for (int i = 0; i < mymenu.menusize - 1; i++)
		{
			if (mymenu.prices[i] > mymenu.prices[i + 1])
			{
				bsHappened = true;

				// back up the bottom item in array
				priceTemp = mymenu.prices[i];
				nameTemp = mymenu.names[i];

				// set the bottom from the top
				mymenu.prices[i] = mymenu.prices[i + 1];
				mymenu.names[i] = mymenu.names[i + 1];

				// set the top from the backed up bottom
				mymenu.prices[i + 1] = priceTemp;
				mymenu.names[i + 1] = nameTemp;
			}
		}
		if (!bsHappened)
		{
			break;
		}
	}

	return mymenu;
}



