#pragma once

#include "ColorConsts.h"
#include "Array2D.h"
#include "BLOCK.h"

class blockArray2D :public Array2D<BLOCK>
{
	public:

	blockArray2D();
	~blockArray2D();
	blockArray2D(const int &_i, const int &_j);

	void init(const int &_i, const int &_j);
	void show();
};

blockArray2D::blockArray2D()
{
	
}

blockArray2D::~blockArray2D()
{
	delete[] buf;
}

blockArray2D::blockArray2D(const int &_i, const int &_j)
{
	init(_i, _j);
}

void blockArray2D::init(const int &_i, const int &_j)
{
	i = _i;
	j = _j;

	if (buf != NULL) delete[] buf;
	buf = new BLOCK[i * j];

	BLOCK *suf = buf + i * j;
	for (BLOCK *itr = buf; itr < suf; itr++)
	{
		itr->init(itr - buf, EMPTY, _BLACK);
	}
}

void blockArray2D::show()
{
	for (int _i = 0; _i < i; _i++)
	{
		for (int _j = 0; _j < j; _j++)
		{
			(*this)[_i][_j].show();
		}
		putchar('\n');
	}
}