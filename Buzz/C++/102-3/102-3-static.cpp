#include <iostream>
#include <string>
using namespace std;


void Whoa()
{
	int count = 0;
	count++;
	cout << count << "\n";
}

void Whoa2()
{
	static int count = 0;
	count++;
	cout << count << "\n";
}



int main()
{
	Whoa();
	Whoa();
	Whoa();

	Whoa2();
	Whoa2();
	Whoa2();

	cin.get();
	return 0;
}

