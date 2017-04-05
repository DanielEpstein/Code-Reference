#include <iostream>
#include <string>

using namespace std;

struct Product
{
	string Name;
	double Price;
};

struct Inventory
{
	Product* Products;
	unsigned int Count; // how many products
};


void InitInventory(Inventory* inventory)
{
	inventory->Products = NULL;
	inventory->Count = 0;
}

void AddProduct(Inventory* inventory, Product product)
{
	if (inventory->Products == NULL) // if this is the first time a product is added
	{
		inventory->Products = new Product[1]; // 
		inventory->Products[0] = product;
		inventory->Count = 1;
	}
	else
	{
		Product* temp = inventory->Products; //backup the existing products
		inventory->Products = new Product[inventory->Count + 1]; // expand the product array by size by 1

		for (unsigned int i = 0; i < inventory->Count; i++) //put existing product back in new expanded array
			inventory->Products[i] = temp[i];

		inventory->Products[inventory->Count] = product; // add the new product to the end of the array
		inventory->Count++; // update the inventory product count

		delete [] temp; // remove the backup
	}
}

void DeleteInventory(Inventory* inventory)
{
	if (inventory->Products == NULL)
		return;

	delete [] inventory->Products;
	inventory->Count = 0;
	inventory->Products = NULL;
}

int main()
{
	Inventory inventory; // create a new data stucture
	InitInventory(&inventory); //initialize the new data stucture to null and 0

	while (true) // create a new product and fill it with data from the user
	{
		Product p;
		cout << "Enter Product Name or \"\" to end: ";
		getline(cin, p.Name);

		if (p.Name == "")
			break;

		cout << "Enter Price: ";
		cin >> p.Price;
		cin.ignore();

		AddProduct(&inventory, p); // add the product to the inventory
	}

	for (unsigned int i = 0; i < inventory.Count; i++) // display the products that are in the inventory
	{
		cout << "Product[" << (i + 1) << "] - " << inventory.Products[i].Name << " Price: " << inventory.Products[i].Price << "\n";
	}

	DeleteInventory(&inventory); // delete the inventory

	cin.get();
	return 0;
}