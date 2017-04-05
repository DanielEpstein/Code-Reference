#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

enum InventoryStatus
{
	Instock,
	OutOfStock,
	Backorder,
};

struct Product
{
	string Name;
	string Notes;
	double Price;
	InventoryStatus Status;
};

void DisplayProduct(Product prod)
{
	cout << "Product Name: " << prod.Name << " has these notes: " << prod.Notes << " and costs $" << prod.Price << "\n";
	if (prod.Status == Instock)
		cout << " -- in stock\n";
	if (prod.Status == OutOfStock)
		cout << " -- out of stock\n";
	if (prod.Status == Backorder)
		cout << " -- on backorder\n";
}

Product GetProductFromInput()
{
	Product temp;
	cout << "Enter name: ";
	getline(cin, temp.Name);
	cout << "Enter Price: ";
	cin >> temp.Price;
	cin.ignore();
	cout << "Enter Notes: ";
	getline(cin, temp.Notes);
	return temp;
}

void SaveProducts(vector<Product> inventory, string filename)
{
	ofstream fout;
	fout.open(filename);

	for (auto i = inventory.begin(); i != inventory.end(); i++)
	{
		Product product = *i;
		fout << product.Name << "\n" << product.Notes << "\n" << product.Price << "\n" << product.Status << "\n";

	}

	fout.close();
}

vector<Product> LoadProducts(string filename)
{
	vector<Product> inventory;
	ifstream fin;
	fin.open(filename);

	while (fin.peek() != ifstream::traits_type::eof())
	{
		Product temp;
		getline(fin, temp.Name);
		getline(fin, temp.Notes);
		fin >> temp.Price;
		fin.ignore();

		int tempStatus;
		fin >> tempStatus;
		fin.ignore();
		temp.Status = (InventoryStatus)tempStatus;

		inventory.push_back(temp);
	}
	return inventory;
}


int main()
{
	// vector<Product> inventory;
	// Product p1 = { "Product 1", "1Notes", 23, Instock };
	// Product p2 = { "Product 2", "2Notes", 231, OutOfStock };
	// Product p3 = { "Product 3", "3Notes", 233, Backorder };
	// Product p4 = { "Product 4", "4Notes", 23432, Instock };
	// 
	// inventory.push_back(p1);
	// inventory.push_back(p2);
	// inventory.push_back(p3);
	// inventory.push_back(p4);
	// 
	// SaveProducts(inventory, "Products.txt");
	vector<Product> inventory2 = LoadProducts("Products.txt");

	for (auto i = inventory2.begin(); i != inventory2.end(); i++)
	{
		DisplayProduct(*i);
	}

	cin.get();
	return 0;
}