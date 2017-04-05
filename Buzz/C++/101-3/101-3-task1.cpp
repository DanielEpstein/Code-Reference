// have a string array(using std::string) of four items in length
// allow the user to enter data for each item in the array
// print out each item

#include <iostream>
#include <string>
using namespace std;

int main()
{
	string str[4];

	int index = 0;

	while (index < 4)
	{
		cout << " Please enter string number " << index << ": ";
		getline(cin, str[index]);
		index++;
	}


	index = 0;
	while (index < 4)
	{
		cout << str[index] << "\n";
		index++;
	}


	cin.ignore();
	cin.get();
	return 0;
}