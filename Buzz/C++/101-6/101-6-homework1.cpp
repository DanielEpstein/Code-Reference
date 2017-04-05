#include <iostream>
#include <string>

using namespace std;


enum MenuState
{
	DisplayMenu,
	AddProduct,
	DeleteProduct,
	DisplayProducts,
	SortProducts,
	ExitProgram
};

struct Product
{
	string Name;
	double Price;
};

struct Inventory
{
	Product* Products;
	unsigned int count;
};

void initInventory(Inventory* inventory)
{
	inventory->Products = NULL;
	inventory->count = 0;
}


// DisplayMenu:
// AddProduct:
// DeleteProduct:
// DisplayProducts:
// SortProducts:
// ExitProgram:




void displayMenu()
{
	cout << " [1] DisplayMenu\n" << " [2] AddProduct\n" << " [3] DeleteProduct\n" << " [4] DisplayProducts\n" << " [5] SortProducts\n" << " [0] ExitProgram\n";
}

void addProduct(Inventory* inventory, Product product)
{
	if (inventory->Products == NULL)
	{
		inventory->Products = new Product[1];
		inventory->Products[0] = product;
		inventory->count = 1;
	}
	else
	{
		Product* temp = inventory->Products;
		inventory->Products = new Product[inventory->count + 1];

		for (unsigned int i = 0; i < inventory->count; i++)
			inventory->Products[i] = temp[i];
		
		
		inventory->Products[inventory->count] = product;
		inventory->count++;

		delete [] temp;
	}
}


void deleteInventory(Inventory* inventory)
{
	if (inventory->Products == NULL)
		return;

	delete [] inventory->Products;
	inventory->Products = NULL;
	inventory->count = 0;
}

void displayInventory(Inventory inventory)
{
	for (unsigned int i = 0; i < inventory.count; i++)
	{
		cout << " Index: " << i << " Product Name: " << inventory.Products[i].Name << " Product Price: " << inventory.Products[i].Price << "\n";
	}
}


void displayAverage()
{

}


int getInt(string prompt)
{
	int myInt;
	cout << prompt << ": ";
	cin >> myInt;
	return myInt;
}

int getInt()
{
	return getInt("Please enter an Int");
}

int main()
{
	Inventory inventory;
	initInventory(&inventory);

	MenuState menuselection;
	bool Exit = false;

	while (!Exit)
	{
		switch (menuselection)
			case DisplayMenu: displayMenu(); break;
			case AddProduct:
			case DeleteProduct:
			case DisplayProducts:
			case SortProducts:
			case ExitProgram:
			default: DisplayMenu;
	}


	while (true)
	{
		Product productinput;

		cout << "\nPlease enter a Product Name: ";
		getline(cin, productinput.Name);

		if (productinput.Name == "")
			break;

		cout << "\nPlease enter a Product Price: ";
		cin >> productinput.Price;
		cin.ignore();

		addProduct(&inventory, productinput);
	}
	

	displayInventory(inventory);

	deleteInventory(&inventory);


	cin.get();
	return 0;
}