#include <iostream>
#include <string>

using namespace std;

struct Product
{
	string Name;
	double Price;
	Product* Next;
};

class Inventory
{
	Product* _products;
	int _count;

public:

	Inventory()
	{
		_products = NULL;
		_count = 0;
	}

	~Inventory()
	{
		if (_products != NULL)
		{
			Product* temp;
			while (_products->Next != NULL)
			{
				temp = _products->Next;
				delete _products;
				_products = temp;
			}
			delete _products;
		}
	}

	void AddProduct(Product* product)
	{
		if (_products == NULL)
		{
			_products = product;
			_products->Next = NULL;
		}
		else
		{
			Product* temp(_products);
			_products = product;
			_products->Next = temp;
		}
	}

	Product* CreateProduct()
	{
		Product* temp = new Product;
		cout << " Please enter a Name: ";
		getline(cin, temp->Name);

		
		cout << " Please enter a Price: ";
		cin >> temp->Price;
		cin.ignore();

		temp->Next = NULL;
		return temp;
	}

	void Display()
	{
		Product* temp = _products;
		while (temp != NULL)
		{
			cout << " Name: " << temp->Name << " Price: " << temp->Price << "\n";
			temp = temp->Next;
		}
	}
};

int main()
{
	Inventory inventory;

	
	inventory.AddProduct(inventory.CreateProduct());
	inventory.AddProduct(inventory.CreateProduct());
	inventory.AddProduct(inventory.CreateProduct());

	inventory.Display();


	cout << " END!";
	cin.get();
	return 0;
}