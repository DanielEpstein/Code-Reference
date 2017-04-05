#include <iostream>
#include <vector>

using namespace std;

const double PI = 3.14;

class IGameObject
{
public:
	virtual int GetId() = 0;
	virtual void Update() = 0;
};

class IShape
{
public:
	virtual int GetCorners() = 0;
	virtual double GetArea() = 0;
};

class Engine
{
	vector<IGameObject*> _gameObjects;

public:
	void Add(IGameObject* gameObject)
	{
		_gameObjects.push_back(gameObject);
	}

	void Update()
	{
		for (auto i = _gameObjects.begin(); i != _gameObjects.end(); i++)
		{
			(*i)->Update();
		}
	}
	void Render()
	{
		for (auto i = _gameObjects.begin(); i != _gameObjects.end(); i++)
		{
			auto shape = dynamic_cast<IShape*>(*i);
			if (shape == NULL)
				continue;

			cout << "Rendering shape with area: " << shape->GetArea() << "\n";
		}
	}
};

class Rectangle : public IShape, public IGameObject
{
	double _width;
	double _hight;
public:
	virtual int GetId() { return 0; }
	virtual void Update()
	{
		_width -= 10;
	}

	void SetSize(double width, double hight)
	{
		_width = width;
		_hight = hight;
	}
	virtual int GetCorners() { return 4; }
	virtual double GetArea() { return _width * _hight; }

};

class Square : public IShape, public IGameObject
{
	double _size;
public:
	virtual int GetId() { return 0; }
	virtual void Update()
	{
		_size -= 5;
	}
	void SetSize(double size)
	{
		_size = size;
	}
	virtual int GetCorners() { return 4; }
	virtual double GetArea() { return _size * _size; }
};

class Circle : public IShape, public IGameObject
{
	double _radius;
public:
	virtual int GetId() { return 0; }
	virtual void Update()
	{
		_radius += 2;
	}
	double GetRadius() { return _radius; }
	void SetRadius(double radius) { _radius = radius; }

	virtual int GetCorners() { return 0; }
	virtual double GetArea() { return PI * _radius * _radius; }
};

class Player : public IGameObject
{
	virtual int GetId() { return 0; }
	virtual void Update()
	{
		cout << "PEW PEW PEW!!!";
	}
};


int main()
{
	Rectangle r1, r2;
	Square s1;
	Circle c1, c2;
	Player p1;

	r1.SetSize(100, 30);
	r2.SetSize(432, 5423);
	s1.SetSize(490);
	c1.SetRadius(4);
	c2.SetRadius(10);

	Engine engine;
	engine.Add(&r1);
	engine.Add(&r2);
	engine.Add(&s1);
	engine.Add(&c1);
	engine.Add(&c2);
	engine.Add(&p1);

	while (true)
	{
		engine.Update();
		engine.Render();

		cout << "Hit Enter";
		cin.get();
	}

	cin.get();
	return 0;
}

