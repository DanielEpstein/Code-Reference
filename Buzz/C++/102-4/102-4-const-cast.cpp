#include <iostream>

using namespace std;

class Position
{
private:
	int _x, _y;

public:
	int GetX() const { return _x; }
	int GetY() const { return _y; }

	void SetX(int x) { _x = x; }
	void SetY(int y) { _y = y; }

};

void Blegh(const Position& pos)
{
	// cant pos.SetX(100);
	// so you can const_cast as below, this helps with dealing with external libs that might have things that are const

	Position& pos2 = const_cast<Position&>(pos);
	pos2.SetX(100);
}



int main()
{
	Position pos;
	pos.SetX(10);
	pos.SetY(40);


	Blegh(pos);

	cout << pos.GetX();

	cin.get();
	return 0;
}