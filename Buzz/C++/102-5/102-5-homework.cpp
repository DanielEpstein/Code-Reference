// Write a BigInt class
// A BigInt class can reprecent an int of any numeric value,
// unlike fixed width ints(for example, the primative int type).
// 
// Must support the following operations :
// copy ctor, dtor, =
// +, -, +=, -=, *, *=
// == , != , <, >, <= , >=
// unaray -
// 
// ostream >>
// istream <<
// 
// size of array of ints * max value of int
// std::numeric_limits<int>:max();
#include <iostream>
#include <vector>

using namespace std;

class BigInt
{
	const int IntMax = std::numeric_limits<int>::max();
	vector<int> IntVector;

};

int main()
{
	BigInt bi;


	cin.get();
	return 0;
}