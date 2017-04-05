#include <iostream>
#include <string>
#include <vector>
using namespace std;

enum InventoryStatus
{
	InStock,
	OutOfStock,
	BackOrder
};

struct Product
{
	string Name;
	string Notes;
	double Price;
	InventoryStatus Status;
};

void DisplayProduct(Product product)
{
	cout << "Product Name: " << product.Name << " has these notes: " << product.Notes << "and costs $" << product.Price << "\n";
	if (product.Status == InStock)
		cout << " -- in stock\n";
	else if (product.Status == OutOfStock)
		cout << " -- out of stock\n";
	else if (product.Status == BackOrder)
		cout << " -- on backorder\n";
}

Product GetProduct()
{
	Product p;
	cout << "Name: ";
	getline(cin, p.Name);

	cout << "Notes: ";
	getline(cin, p.Notes);

	cout << "Price: ";
	cin >> p.Price;
	cin.ignore();

	return p;
}

int main()
{
	vector<int> numbers;

	while (true)
	{
		int input;
		cin >> input;
		cin.ignore();

		if (input == 0)
			break;
		else
			numbers.push_back(input);
	}

	double sum = 0;
	for (vector<int>::iterator i = numbers.begin(); i != numbers.end(); i++)
	{
		// not a pointer, its a operator overload
		sum += *i;
	}

	sum = 0;
	for (unsigned int i = 0; i < numbers.size(); i++)
	{
		sum += numbers[i];
	}

	double average = sum / numbers.size();
	cout << "The average is: " << average;

	cin.get();
	return 0;
}