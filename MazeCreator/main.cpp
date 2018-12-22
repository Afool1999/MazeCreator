#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include "CONSTS.h"
#include "BLOCK.h"
#include "ColorConsts.h"
#include "Array2D.h"
#include "Room.h"
#include "MazeCreator.h"
#include "Coordinate.h"




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

	freopen("data.in", "w", stdout);

	MazeCreator mz;

	return 0;
}