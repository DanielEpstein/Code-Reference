#include <iostream>

using namespace std;

class Person
{
	const int _age;
	
public:
	Person(int age) : _age(age)
	{

	}

	int GetAge() { return _age; }

};


int main()
{
	Person p1(10);
	Person p2(20);

	cout << p1.GetAge() << "\n";
	cout << p2.GetAge() << "\n";

	cin.get();
	return 0;
}