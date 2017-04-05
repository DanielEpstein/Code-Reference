#include <iostream>
#include <string>

using namespace std;


class Vector2
{
	float _x, _y;

public:
	Vector2(float x, float y) : _x(x), _y(y)
	{
	}

	float GetX() const { return _x; }
	float GetY() const { return _y; }

	// Vector2 operator + (const Vector2& rhs) const
	// {
	// 	Vector2 local(_x + rhs._x, _y + rhs._y);
	// 	return local;
	// }

	Vector2 operator + (const Vector2& rhs) const
	{
		Vector2 local(*this);
		return local += rhs;
	}

	Vector2& operator += (const Vector2& rhs)
	{
		_x += rhs._x;
		_y += rhs._y;
		return *this;
	}

	Vector2& operator++() // prefix
	{
		_x++;
		_y++;
		return *this;
	}

	Vector2 operator++(int) //postfix
	{
		Vector2 result(*this);
		operator++();
		return result;
	}
};


// operator overloading outside of the class
Vector2 operator * (const Vector2& lhs, const Vector2& rhs)
{
	return Vector2(lhs.GetX() * rhs.GetX(), lhs.GetY() * rhs.GetX());
}

ostream& operator << (ostream& out, const Vector2& rhs)
{
	out << "(" << rhs.GetX() << ", " << rhs.GetY() << ")";
	return out;
}

int main()
{
	// Vector2 MyObject1(1, 2);
	// Vector2 MyObject2(1, 2);
	// cout << (MyObject1 + MyObject2).GetX();

	// Vector2 result = MyObject1 + MyObject2;
	// 
	// cout << result.GetX() << "\n";
	// cout << result.GetY() << "\n";

	// << overload
	// Vector2 vector2(2, 2);
	// cout << "Vector2: " << vector2;

	// * overload
	Vector2 one(1, 2);
	Vector2 two(1, 2);
	cout << one * two;

	cin.get();
	return 0;
}