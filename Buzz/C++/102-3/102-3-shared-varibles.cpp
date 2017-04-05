#include <iostream>
#include <string>
using namespace std;

class Person
{
	string _name;
	int _age;
public:
	Person(string name, int age) : _name(name), _age(age)
	{
		NumberOfPeople++;
	}

	string GetName() { return _name; }

	// static = shared/global (static feild) , they are also not inherited
	static int NumberOfPeople;

	static void StaticMethod()
	{
		cout << "WOAH!\n";
	}
	
	static void StaticMethod2(Person person)
	{
		cout << person._name << "cool\n";
	}
};

// initialising static members
int Person::NumberOfPeople = 0;


int main()
{
	Person::StaticMethod();
	cout << "There are " << Person::NumberOfPeople << " people!\n";

	Person person1("Nelson, ", 1024);

	// better to access static member via the type than via an instance
	cout << "There are " << Person::NumberOfPeople << " people!\n";

	Person person2("Rainbox Dash, ", 2);
	cout << "There are " << person1.NumberOfPeople << " people!\n";

	// user static member to access feild from an instance that passed in
	Person::StaticMethod2(person1);

	cin.get();
	return 0;
}