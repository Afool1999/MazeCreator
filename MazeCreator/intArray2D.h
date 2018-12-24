#pragma once

#include <cstdio>
#include "Array2D.h"

class intArray2D :public Array2D<int>
{
	public:

	intArray2D();
	~intArray2D();
	intArray2D(const int &_i, const int &_j);

	void init(const int &_i, const int &_j);
	void show();
};

intArray2D::intArray2D()
{

}

intArray2D::~intArray2D()
{
	delete[] buf;
}

intArray2D::intArray2D(const int &_i, const int &_j)
{
	init(_i, _j);
}

void intArray2D::init(const int &_i, const int &_j)
{
	i = _i;
	j = _j;

	if (buf != NULL) delete[] buf;
	buf = new int[i * j];

	int *suf = buf + i * j;
	for (int *itr = buf; itr < suf; itr++)
	{
		*itr = 0;
	}
}

void intArray2D::show()
{
	for (int _i = 0; _i < i; _i++)
	{
		for (int _j = 0; _j < j; _j++)
		{
			printf("%d ", (*this)[_i][_j]);
		}
		putchar('\n');
	}
}