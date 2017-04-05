#include <vector>
#include "types.h"

using namespace std;

vector<Product> BubbleSwap(vector<Product> products)
{
	Product productTemp;
	bool enableswap;
	while (true)
	{
		enableswap = false;
		for (int i = 0; i < products.size() - 1; i++)
		{
			if (products[i].Price > products[i + 1].Price)
			{
				enableswap = true;
				productTemp = products[i];
				products[i] = products[i + 1];
				products[i + 1] = productTemp;
			}
		}
		if (!enableswap)
		{
			break;
		}
	}
	return products;
}