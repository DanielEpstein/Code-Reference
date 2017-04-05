// Create a function that takes a product* and allows the user to set its data.
// Invokle the function from main, passing in an address to a product allocated on mains stack.

#include <iostream>
#include <string>

using namespace std;

struct Product
{
	string Name;
	double Price;
	string Notes;
};


void CreateProduct(Product* product)
{
	cout << "Please enter a Name: ";
	getline(cin, product->Name);
	
	cout << "Please enter a Price: ";
	cin >> product->Price;
	
	cin.ignore();

	cout << "Please enter a Note: ";
	getline(cin, product->Notes);
}


void PrintProduct(Product product)
{
	cout << "\nName: " << product.Name;
	cout << "\nPrice: " << product.Price;
	cout << "\nNotes: " << product.Notes;
}


int main()
{
	Product p1;

	CreateProduct(&p1);

	PrintProduct(p1);



	cin.get();
	return 0;
}