#pragma once

#include "intArray2D.h"

class boolArray2D :public intArray2D
{
	public:
	boolArray2D();
	boolArray2D(const int &_i, const int &_j);
};

boolArray2D::boolArray2D()
{

}

boolArray2D::boolArray2D(const int &_i, const int &_j)
{
	init(_i, _j);
}