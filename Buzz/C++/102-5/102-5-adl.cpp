#include <iostream>
#include <string>


// Argument-dependent lookup

namespace Whoa
{
	class Test
	{
	};

	void DoStuff(Test t)
	{
		std::cout << "Whoa::DoStuff";
	}

}

int main()
{
	Whoa::Test test;
	DoStuff(test);

	std::cin.get();
	return 0;
}