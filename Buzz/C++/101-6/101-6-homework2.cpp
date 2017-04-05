#include <iostream>
#include <string>

using namespace std;

struct Product
{
	string Name;
	double Price;
	Product* Next;
};

struct Inventory
{
	Product* Products;
	unsigned int Size;
	
};

void AddProduct(Inventory* inventory, Product product)
{
	if (inventory->Products == NULL)
	{
		inventory->Products = new Product;
		*inventory->Products = product;
		inventory->Products->Next = NULL;
		inventory->Size = 1;
	}
	else
	{
		Product* temp = inventory->Products;
		inventory->Products = new Product;
		*inventory->Products = product;
		inventory->Products->Next = temp;
		inventory->Size++;
	}
}


void DisplyAveragePrice(Inventory* inventory)
{
	double myDouble = 0;
	unsigned int count = 0;
	Product* temp = inventory->Products;

	while (temp != NULL)
	{
		myDouble += temp->Price;
		temp = temp->Next;
		count++;
	}
	cout << " myDouble: " << myDouble << " count: " << count << "\n";
	cout << " Aveage Price: " << myDouble / count << "\n";
}



void DisplayInventory(Inventory* inventory)
{
	if (inventory->Size > 0)
	{

		cout << " Product Count: " << inventory->Size << "\n\n";

		Product* CurrentProduct = inventory->Products;
		unsigned int productnumber = 1;

		// cout << " Number: " << productnumber << " Name: " << CurrentProduct->Name << " Price: " << CurrentProduct->Price << "\n";
		// cout << " Number: " << productnumber + 1 << " Name: " << CurrentProduct->Next->Name << " Price: " << CurrentProduct->Next->Price << "\n";

		while (CurrentProduct != NULL)
		{
			cout << " Number: " << productnumber << " Name: " << CurrentProduct->Name << " Price: " << CurrentProduct->Price << "\n";
			CurrentProduct = CurrentProduct->Next;
			productnumber++;
		}
	}
	else
	{
		cout << " Inventory is Empty\n";
	}
}


void InitInventory(Inventory* inventory)
{
	inventory->Products = NULL;
	inventory->Size = 0;
}

void DeleteAllProducts(Inventory* inventory)
{
	if (inventory->Products == NULL)
		return;

	Product* temp;
	while (inventory->Products->Next != NULL)
	{
		temp = inventory->Products->Next;
		delete inventory->Products;
		inventory->Products = temp;
	}
	delete inventory->Products;
	
	inventory->Products = NULL;
	inventory->Size = 0;
}



int main()
{
	Inventory inventory1;
	InitInventory(&inventory1);

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

		AddProduct(&inventory1, productinput);
	}

	DisplayInventory(&inventory1);
	DisplyAveragePrice(&inventory1);
	DeleteAllProducts(&inventory1);

	cin.get();
	return 0;
}