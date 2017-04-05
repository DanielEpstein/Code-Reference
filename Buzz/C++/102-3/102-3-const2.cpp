#include <iostream>

using namespace std;


int main()
{
	int a = 10;
	int b = 20;

	const int* ptrToConstInt = &a;
	
	int* const consIntPtr = &a;
	const int* const constPtrToConstInt = &a;

	cin.get();
	return 0;
}