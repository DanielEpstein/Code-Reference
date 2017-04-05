#include <iostream>
#include <string>

using namespace std;

struct Product
{
	string Name;
	double Price;
};

// a new product get created on the stack
void GetProductDataFromUser1(Product product)
{
	cout << "Product Name: ";
	getline(cin, product.Name);

	cout << "Product Price: ";
	cin >> product.Price;
	cin.ignore();
}

// a pointer to the exsisting product passed in that is already on the stack (asterisk)
void GetProductDataFromUser2(Product* product)
{
	// product->Name   is the same as
	// (*product).Name


	cout << "Product Name: ";
	getline(cin, product->Name);

	cout << "Product Price: ";
	cin >> product->Price;
	cin.ignore();
}

void DisplayProduct(Product product)
{
	cout << "Product Name: " << product.Name << "\n";
	cout << "Product Price " << product.Price << "\n";
}

int main()
{
	// p1 gets pushed onto the stack
	Product p1;
	GetProductDataFromUser1(p1);
	// the new product that was created on the stack when this function was called is now gone
	DisplayProduct(p1);

	// p2 gets pushed onto the stack
	Product p2;
	// & the address of p2 (ampersand symbol)
	GetProductDataFromUser2(&p2);
	DisplayProduct(p2);

	cin.get();
	return 0;
}