#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "types.h"

using namespace std;

vector<Product> LoadProducts(string filename)
{
	vector<Product> inventory;
	ifstream fin;
	fin.open(filename);

	while (fin.peek() != ifstream::traits_type::eof())
	{
		Product temp;
		getline(fin, temp.Name);
		getline(fin, temp.Description);
		fin >> temp.Price;
		fin.ignore();

		inventory.push_back(temp);
	}
	return inventory;
}

void SaveProducts(vector<Product> inventory, string filename)
{
	ofstream fout;
	fout.open(filename);

	for (auto i = inventory.begin(); i != inventory.end(); i++)
	{
		Product product = *i;
		fout << product.Name << "\n" << product.Description << "\n" << product.Price << "\n";
	}

	fout.close();
}