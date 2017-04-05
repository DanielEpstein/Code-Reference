#include <iostream>

using namespace std;


int main()
{
	auto i = 1;
	cout << i++ << "\n"; // postfix
	cout << ++i << "\n"; // prefix
	cout << i << "\n";

	cout << "\n";

	i = 1;
	cout << ++i << "\n";
	cout << i++ << "\n";
	cout << i << "\n";

	cin.get();
	return 0;
}