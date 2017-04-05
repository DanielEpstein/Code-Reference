#include <iostream>



class storage
{
public:
	int myNum;
	storage* node;
};

void printNum(storage* ptr)
{
	std::cout << ptr->myNum << std::endl;
}


int main()
{
	storage* beginning = new storage;
	storage* lastPtr = new storage;
	storage* runningPtr = new storage;

	int userInput = 1;

	int count = 1;
	int i = 1;

	while (userInput != 0)
	{
		std::cout << "Please enter a number: ";
		std::cin >> userInput;
		if (count == 1)
		{
			beginning->myNum = userInput;
			storage* ptr = new storage;
			ptr->myNum = 0;
			ptr->node = nullptr;
			beginning->node = ptr;
			lastPtr = ptr;

		}
		else
		{
			lastPtr->myNum = userInput;
			storage* ptr = new storage;
			ptr->myNum = 0;
			ptr->node = nullptr;
			lastPtr->node = ptr;
			lastPtr = ptr;
		}

		count++;


	}

	lastPtr->node = nullptr;

	while (count > i)
	{
		if (i == 1)
		{
			printNum(beginning);
			runningPtr = beginning->node;
		}
		else
		{
			printNum(runningPtr);
			runningPtr = runningPtr->node;


		}
		i++;
	}

	return 0;
}