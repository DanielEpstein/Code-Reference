#include <iostream>

using namespace std;

class ClassB
{
public:
	ClassB(int whoa)
	{

	}
};

class ClassA
{
private:
	int& _myField;
	ClassB _otherObject;

public:
	ClassA(int& myParam) : _myField(myParam), _otherObject(10)
	{

	}
};

int main()

{
	int myLocalVar = 10;
	ClassA cls1(myLocalVar);

	return 0;
}