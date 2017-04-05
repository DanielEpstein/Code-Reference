#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Vector2
{
	int _x, _y;

public:
	Vector2() : _x(0), _y(0) {}  // default ctor

	Vector2(int x, int y) : _x(x), _y(y) // ctor
	{
	}

	// rhs: right hand side a naming convention for operator overloading
	Vector2(const Vector2& rhs) : _x(rhs._x), _y(rhs._y) // copy constructor that c++ creates
	{
	}
	
	int GetX() const { return _x; }
	int GetY() const { return _y; }

	Vector2& operator = (const Vector2& rhs) // asignment operator that c++ creates 
	{
		if (&rhs == this)
			return *this;

		_x = rhs._x;
		_y = rhs._y;
		return *this;
	}
};

int main()
{
	Vector2 vect2(1, 2);

	Vector2 copy(vect2); // <- ctor: Vector(const Vector2& rhs)

	Vector2 copy2; // <- ctor: Vector2()
	copy = vect2; // <- operator = (const Vector2& rhs)

	cin.get();
	return 0;
}


