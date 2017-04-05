// Write a fuction that returns a dynamically allocated Product
// Fill the values of the product with input from the user.
// invoke from main and be sure to deallocate the memory!

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
	Product* product = new Product;
	cout << "Name: ";
	getline(cin, product->Name);

	cout << "Price: ";
	cin >> product->Price;
	cin.ignore();

	return product;
}


int main()
{
	Product* product = GetProduct();

	cout << "Name: " << product->Name << "\n";
	cout << "Price: " << product->Price << "\n";
	
	delete product;
	cin.get();
	return 0;
}