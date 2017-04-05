#include <iostream>
#include <string>

using namespace std;


string promptsymbol = ": ";


int GetInt(string prompt)
{
	int temp;
	cout << prompt << promptsymbol;
	cin >> temp;
	cin.ignore();
	return temp;
}

int GetInt()
{
	return GetInt("Enter a number");
}



string GetString(string prompt)
{
	string temp;
	cout << prompt << promptsymbol;
	getline(cin, temp);
	return temp;
}

string GetString()
{
	return GetString("Enter a string");
}