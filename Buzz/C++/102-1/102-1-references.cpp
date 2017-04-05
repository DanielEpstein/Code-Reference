#include <iostream>

using namespace std;


int main()
{
	int number1 = 10;
	int number2 = 20;


	// creates a refernec to number1
	int& numberRef = number1;
	
	// this number1 via reference to number 2 value
	numberRef = number2;


	cout << number1 << "\n" << number2 << "\n" << numberRef;

	cin.get();
	return 0;
}