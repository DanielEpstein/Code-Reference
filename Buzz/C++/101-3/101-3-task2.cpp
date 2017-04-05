#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main()
{

	for (int i = 50;i <= 1000;i += 5)
	{
		cout << i;
		if (i < 1000)
		{
			cout << ", ";
		}
	}


	cin.ignore();
	cin.get();
	return 0;
}