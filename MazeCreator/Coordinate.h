#pragma once

/*
	坐标/向量 类
	计算 坐标/向量 之间的转化以及叉积
*/

class Coordinate {

	public:

	int x, y;

	Coordinate() :x(0), y(0) {};
	Coordinate(const int &_x, const int &_y) :x(_x), y(_y) {};
	void init(const int &_x, const int &_y);

	Coordinate operator+(const Coordinate &other);
	Coordinate append(const Coordinate &other);
	Coordinate add(const int &_x, const int &_y);

	Coordinate operator-(const Coordinate &other);
	Coordinate decline(const Coordinate &other);
	Coordinate dec(const int &_x, const int &_y);

//	向量叉积
	int crossProduct(const Coordinate &other);

//	向量点积
	Coordinate operator*(const Coordinate &other);

//	判断向量共线时的包含关系
	bool isInclude(const Coordinate &other);

	void show();

};

void Coordinate::init(const int &_x, const int &_y)
{
	x = _x;
	y = _y;
}

Coordinate Coordinate::operator+(const Coordinate &other)
{
	Coordinate res = *this;
	res.append(other);
	return res;
}

Coordinate Coordinate::append(const Coordinate &other)
{
	Coordinate res = *this;
	res.add(other.x, other.y);
	return *this = res;
}

Coordinate Coordinate::add(const int &_x, const int &_y)
{
	Coordinate res = *this;
	res.x += _x;
	res.y += _y;
	return *this = res;
}

Coordinate Coordinate::operator-(const Coordinate &other)
{
	Coordinate res = *this;
	res.decline(other);
	return res;
}

Coordinate Coordinate::decline(const Coordinate &other)
{
	Coordinate res = *this;
	res.dec(other.x, other.y);
	return *this = res;
}

Coordinate Coordinate::dec(const int &_x, const int &_y)
{
	Coordinate res = *this;
	res.x -= _x;
	res.y -= _y;
	return *this = res;
}

int Coordinate::crossProduct(const Coordinate &other)
{
	int res = 0;
	res = x * other.y - y * other.x;
	return res;
}

Coordinate Coordinate::operator*(const Coordinate &other)
{
	Coordinate res = *this;
	res.x *= other.x;
	res.y *= other.y;
	return res;
}

bool Coordinate::isInclude(const Coordinate &other)
{
	if (x * other.x < 0 || y * other.y < 0) return 0;
	if (x == other.x) return abs(y) >= abs(other.y);
	if (y == other.y) return abs(x) >= abs(other.x);
}

void Coordinate::show()
{
	printf("(%d,%d)\n", x, y);
}