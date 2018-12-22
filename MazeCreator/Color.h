#pragma once

#include <cstdio>
#include <cstdlib>
#include "CONSTS.h"

/*
	颜色类
	存储 RGB 颜色信息
*/


class Color {

	public:

	Color() :R(0), G(0), B(0) {};
	Color(const int &_R, const int &_G, const int &_B) :R(_R), G(_G), B(_B) {};
//	输出 RGB 信息
	void show();
	void rand();

	private:

	int R, G, B;

};

void Color::show()
{
//	printf("{%d,%d,%d}", R, G, B);
	printf("%d %d %d ", R, G, B);
}

void Color::rand()
{
	R = randomBetween(55, 255);
	G = randomBetween(55, 255);
	B = randomBetween(55, 255);
}