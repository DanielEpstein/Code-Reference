#include <iostream>
#include <string>

using namespace std;

// _str get initialised to the assigned value (one step)
class GoodClass
{
	string _str;

public:
	GoodClass(string str) : _str(str)
	{
	}
};

// _str get initialised to is default value then it get assigned (two steps)
class BadClass
{
	string _str;

public:
	BadClass(string str)
	{
		_str = str;
	}
};

int main()
{
	

	return 0;
}