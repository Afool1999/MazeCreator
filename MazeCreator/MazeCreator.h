#pragma once

#include "CONSTS.h"

#include "blockArray2D.h"
#include "boolArray2D.h"

#include "BLOCK.h"
#include "Room.h"

#include "STJAlgorithm.h"

#include <ctime> 
#include <vector>

/*
	迷宫建造类

	MazeCreator	初始化迷宫参数
	init		对迷宫进行搭建
*/

using namespace std;

class MazeCreator
{

	public:
	
	MazeCreator();
	void generate();
	void show();
	void test()
	{
		for (int i = 0; i < _CANVAS_WIDTH; i++)
		{
			for (int j = 0; j < _CANVAS_HEIGHT; j++)
			{
				if (mazeMap[i][j].type() == ROOM)
				{
					//putchar('*');
					if(mazeMap[i][j].id()<0)printf("%d ", mazeMap[i][j].id());
					else putchar('*');
				}
				else putchar('0');
			}
			putchar('\n');
		}
	}

	private:

	int width, height;

	blockArray2D mazeMap;

	vector <Room> roomList;

	void generateRooms();
	void generateWays();
	void randomDFS(const int &x, const int &y, boolArray2D *isVisited);

};

MazeCreator::MazeCreator()
{
//	设置随机种子以便随机道路和房间
	srand((unsigned)time(NULL));

	width = _CANVAS_WIDTH;
	height = _CANVAS_HEIGHT;
	roomList.clear();
	generate();
}

void MazeCreator::generate()
{
//	用空白方块初始化 MazeMap	
	mazeMap.init(width, height);

	roomList.clear();
	generateRooms();
	generateWays();
}

void MazeCreator::show()
{
	for (int j = 0; j < height; j++)
	{
		for (int i = 0; i < width; i++)
		{
			mazeMap[i][j].show();
		}
		//putchar('\n');
	}
	//putchar('\n');
}

void MazeCreator::generateRooms()
{
	//	不断尝试生成房间
	
#ifndef _UNDER_TEST
	show();
#endif // !_UNDER_TEST

	Room base;

	for (int i = 0; i < _TRIES; i++)
	{
		base.randomRoom();
		if (base.isNotValid()) continue;

		std::vector<Room>::iterator inf, sup, itr;
		inf = roomList.begin();
		sup = roomList.end();

		bool flg = 0;
		for (itr = inf; itr < sup; itr++)
		{
			if (base.isCollasped(&mazeMap))
			{
				flg = 1;
				break;
			}
		}
		if (flg) continue;
		roomList.push_back(base);
		base.formInMap(&mazeMap);

#ifndef _UNDER_TEST
		show();
#endif // _UNDER_TEST

	}
}

//	待完成

void MazeCreator::randomDFS(const int &x, const int &y, boolArray2D *isVisited)
{
	int randTimes = randomBetween(1, _MAX_STJ) - 1;

	STJAlgorithm formList;
	formList = STJ[randTimes];	
	formList.print();

	Coordinate cur(x, y);

}

void MazeCreator::generateWays()
{
	boolArray2D isVisited(_WIDTH, _HEIGHT);

	for (int i = 0; i < _WIDTH; i++)
	{
		for (int j = 0; j < _HEIGHT; j++)
		{
			int x = i << 1 | 1;
			int y = j << 1 | 1;

			if (mazeMap[x][y].type() == ROOM)
			{
				isVisited[i][j] = TRUE;
			}

			if (!isVisited[i][j])
			{
				randomDFS(i, j, &isVisited);
			}
		}
	}


}