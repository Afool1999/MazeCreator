#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include "CONSTS.h"
#include "BLOCK.h"
#include "ColorConsts.h"
#include "Array2D.h"
#include "Room.h"
#include "MazeCreator.h"
#include "Coordinate.h"
#include "boolArray2D.h"
#include "STJAlgorithm.h"


void init()
{
	_WIDTH = _CANVAS_WIDTH >> 1;
	_HEIGHT = _CANVAS_HEIGHT >> 1;

	STJAlgorithm base(4);

	for (int i = 0; i < _MAX_STJ; i++)
	{
		STJ[i] = base;
		base.findnxt();
	}
}

int main(int argc, char *argv[])
{
	
	if (argc >= 3)
	{
		_CANVAS_WIDTH = stringToInt(argv[1]);
		_CANVAS_HEIGHT = stringToInt(argv[2]);
		if (argc > 3)
		{
			_TRIES = stringToInt(argv[3]);
		}
	}

	init();

#ifndef _UNDER_TEST
	freopen("data.in", "w", stdout);
#endif // _UNDER_TEST

	MazeCreator mz;
	//mz.test();

	return 0;
}