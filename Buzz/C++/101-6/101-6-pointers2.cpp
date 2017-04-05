#include <iostream>

using namespace std;

int main()
{
	int aNumber = 10;
	int* aNumberPointer = &aNumber;

	cout << "aNumber: " << aNumber << "\n";
	cout << "&aNumber: " << &aNumber << "\n";
	cout << "aNumberPointer: " << aNumberPointer << "\n";
	cout << "&aNumberPointer: " << &aNumberPointer << "\n";
	cout << "*aNumberPointer: " << *aNumberPointer << "\n";

	cout << "--------------------\n";

	int aNumber2 = 20;
	int* aNumber2Pointer = &aNumber2;

	cout << "aNumber2: " << aNumber2 << "\n";
	cout << "&aNumber2: " << &aNumber2 << "\n";
	cout << "aNumber2Pointer: " << aNumber2Pointer << "\n";
	cout << "&aNumber2Pointer: " << &aNumber2Pointer << "\n";
	cout << "*aNumber2Pointer: " << *aNumber2Pointer << "\n";

	cin.get();
	return 0;
}