#include <iostream>
#include <string>

using namespace std;

struct Product
{
	string Name;
	double Price;
};


Product* GetProduct()
{
	Product* p1 = new Product;
	cout << "\nPlease enter a Name: ";
	getline(cin, p1->Name);
	


	cout << "\nPlease enter a Price: ";
	cin >> p1->Price;

	cin.ignore();

	return p1;
}



int main()
{
	Product* product = GetProduct();

	cout << product->Name << "\n";
	cout << product->Price << "\n";

	delete product;

	cin.get();
	return 0;
}