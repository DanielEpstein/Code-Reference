#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

int main()
{
	float age;
	string name;

	cout << "Enter your age: ";
	cin >> age;

	cout << "Enter your name: ";
	cin >> name;

	stringstream ss;
	ss << name << " - you are " << fixed << setprecision(4) << (age + 1.0f) << " years old in a year!";

	string output = ss.str();
	cout << output;

	cout << "\nEND OF PROGRAM !";
	cin.ignore();
	cin.get();
	return 0;
}