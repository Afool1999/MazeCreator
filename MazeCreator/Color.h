#pragma once

#include <cstdio>
#include <cstdlib>
#include "CONSTS.h"

/*
	��ɫ��
	�洢 RGB ��ɫ��Ϣ
*/


class Color {

	public:

	Color() :R(0), G(0), B(0) {};
	Color(const int &_R, const int &_G, const int &_B) :R(_R), G(_G), B(_B) {};
//	��� RGB ��Ϣ
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
	R = randomBetween(_MIN_COLOR, _MAX_COLOR);
	G = randomBetween(_MIN_COLOR, _MAX_COLOR);
	B = randomBetween(_MIN_COLOR, _MAX_COLOR);
}