#include <iostream>

using namespace std;

const double PI = 3.14;

class IShape
{

public:
	virtual int GetCorners() = 0;
	virtual double GetArea() = 0;
};


class Circle: public IShape
{
	double _radius;
public:
	
	double GetRadius() { return _radius; }
	void SetRadius(double radius) {	_radius = radius; }
	
	virtual int GetCorners() { return 0; }
	virtual double GetArea() {	return PI * _radius * _radius; }
};

class Rectangle : public IShape
{
	double _width;
	double _hight;
public:
	void SetSize(double width, double hight)
	{
		_width = width;
		_hight = hight;
	}
	virtual int GetCorners() { return 4; }
	virtual double GetArea() { return _width * _hight; }

};

class Square : public IShape
{
	double _size;
public:
	void SetSize(double size)
	{
		_size = size;
	}
	virtual int GetCorners() { return 4; }
	virtual double GetArea() { return _size * _size; }
};




void DisplayShape(IShape* shape)
{
	cout << " This shape has " << shape->GetCorners() << " corners and an area of " << shape->GetArea() << "\n";
}


int main()
{
	Circle circle;
	circle.SetRadius(4);
	DisplayShape(&circle);

	Rectangle rectangle;
	rectangle.SetSize(10, 8);
	DisplayShape(&rectangle);

	Square square;
	square.SetSize(7);
	DisplayShape(&square);

	cin.get();
	return 0;
}

