#include <iostream>
#include <vector>
#include "types.h"

using namespace std;

void ShowProducts(vector<Product> products)
{
	for (unsigned int i = 0; i < products.size(); i++)
	{
		cout << " Index: " << i << " Name: " << products[i].Name << " Price: " << products[i].Price << " Description: " << products[i].Description << "\n";
	}
}