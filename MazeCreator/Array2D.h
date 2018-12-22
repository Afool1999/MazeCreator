#pragma once

#include "BLOCK.h"

//	��̬ģ���ά���飬i/j �ֱ�Ϊ�������ά�����ֵ
//	���� defaultT ��ʼ��������


class Array2D
{
	public:

	Array2D();
	Array2D(const int &_i, const int &_j);
	~Array2D();
	BLOCK *operator[](const int &_i);
	void init(const int &_i, const int &_j);
	void show();

	private:

	int i, j;
	BLOCK *buf;
};


Array2D::Array2D()
{
	
}

Array2D::Array2D(const int &_i, const int &_j)
{
	init(_i, _j);
}

Array2D::~Array2D()
{
	delete[] buf;
}

BLOCK *Array2D::operator[](const int &_i)
{
	return buf + _i * j;
}

void Array2D::init(const int &_i, const int &_j)
{
	if (_i < 0 || _j < 0 || _i % 2 == 0 || _j % 2 == 0)
	{
		puts("invalid input at Array2D.input() !");
		return;
	}

	i = _i;
	j = _j;
	if (buf != NULL) delete[] buf;
	buf = new BLOCK[i * j];
	BLOCK *suf = buf + i * j;
	for (BLOCK *itr = buf; itr < suf; itr++)
	{
		//printf("%d\n", itr - buf);
		itr->init(itr - buf, EMPTY, _BLACK);
		//printf("%d\n", itr->id());
	}
}

void Array2D::show()
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