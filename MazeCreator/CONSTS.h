#pragma once

#include "cstdlib"
#include "Coordinate.h"
#include "STJAlgorithm.h"

//#define _UNDER_TEST

//	������ೣ��

#define TRUE true
#define FALSE false

//	��ɫ����
#define _MAX_COLOR 255
#define _MIN_COLOR 55

//	���巿����󳤿��
#define _RATE (0.618)

//	������С
int _CANVAS_WIDTH = (40 << 1 | 1);
int _CANVAS_HEIGHT = (25 << 1 | 1);

//	ԭʼ��С
int _WIDTH = 0;
int _HEIGHT = 0;

//	�������ɷ���Ĵ���
int _TRIES = (100);

//	����������Ŀ
int _BACKS = 0;

//	����������
#define _MAX_STJ 24
STJAlgorithm STJ[_MAX_STJ];

//	BLOCK ����
#define _BLOCK_TYPES (4)
char const *_TILES[_BLOCK_TYPES] = { "empty", "way", "room", "door" };
#define EMPTY 0
#define WAY 1
#define ROOM 2
#define DOOR 3


//	���巿��ı߳�����ķ�Χ
#define _ROOM_MIN_WIDTH (7)
#define _ROOM_MAX_WIDTH (11)

//	���� ����/��ת ����
const int fx[4] = { 1, 0, -1, 0 };
const int fy[4] = { 0, 1, 0, -1 };

//	���������ೣ��

const Coordinate _GO_R(1, 0);
const Coordinate _GO_L(-1, 0);
const Coordinate _GO_U(0, 1);
const Coordinate _GO_D(0, -1);
const Coordinate _DIR[4] = { _GO_R, _GO_U, _GO_L, _GO_D };

//	���� [inf, sup] �������
int randomBetween(const int &inf, const int &sup)
{
	if (inf > sup)
	{
		puts("invalid input at randomBetween() !");
		return -1;
	}
	int res = 0;
	res = rand() % (sup - inf + 1) + inf;
	return res;
}

template<class T>
T min(const T &a, const T &b)
{
	if (a > b)return b;
	else return a;
}

template<class T>
T max(const T &a, const T &b)
{
	if (a < b)return b;
	else return a;
}

int stringToInt(char *str)
{
	int ret = 0;
	for (; *str != '\0'; ++str)
	{
		ret = ret * 10 + *str - '0';
	}
	return ret;
}