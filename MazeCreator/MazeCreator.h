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
				else if (mazeMap[i][j].type() == WAY) putchar('*');
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
	void randomDFS(const Coordinate &cur, boolArray2D *isVisited);
	void fillAlleys();

	bool isInMap(const Coordinate &cur);

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
	fillAlleys();
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

//	尝试生成房间
void MazeCreator::generateRooms()
{
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

//	随机方向深搜
void MazeCreator::randomDFS(const Coordinate &cur, boolArray2D *isVisited)
{
	//	产生随机方向
	int randTimes = randomBetween(1, _MAX_STJ) - 1;

	STJAlgorithm formList;
	//printf("%d %d\n", cur.x, cur.y);
	formList = STJ[randTimes];	

	Coordinate suc;

	for (int i = 0; i < 4; ++i)
	{
		int id = formList[i];

		suc = cur;
		suc.add(fx[id] << 1, fy[id] << 1);

		if (isInMap(suc) && !(*isVisited)[suc.x >> 1][suc.y >> 1])
		{
			int mx = cur.x + fx[id];
			int my = cur.y + fy[id];

			//printf("%d %d %d %d %d %d\n", cur.x, cur.y, mx, my, suc.x, suc.y);

			mazeMap[mx][my].setParrent(&(mazeMap[cur.x][cur.y]));
			mazeMap[suc.x][suc.y].setParrent(&(mazeMap[mx][my]));

			(*isVisited)[suc.x >> 1][suc.y >> 1] = TRUE;
#ifndef _UNDER_TEST
			show();
#endif // _UNDER_TEST
			randomDFS(suc, isVisited);
		}
	}

}

//	生成道路
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
		}
	}
	for (int i = 0; i < _WIDTH; i++)
	{
		for (int j = 0; j < _HEIGHT; j++)
		{
			int x = i << 1 | 1;
			int y = j << 1 | 1;

			if (!isVisited[i][j])
			{
				isVisited[i][j] = TRUE;
				BLOCK *_parrent = &(mazeMap[x][y]);
				//printf("%d %d\n", _parrent, &(mazeMap[x][y]));
				Color pathColor;
				pathColor.rand();
				_parrent->init(NULL, WAY, pathColor);

				Coordinate cur(x, y);
#ifndef _UNDER_TEST
				show();
#endif // _UNDER_TEST
				randomDFS(cur, &isVisited);
			}
		}
	}

	for(int i=0;i<width;i++)
		for (int j = 0; j < height; j++)
		{
			if (mazeMap[i][j].type() == EMPTY)
				mazeMap[i][j].blockId = -1;
		}
}

void MazeCreator::fillAlleys()
{
	int maxLen = 11111;
	Coordinate *front, *rear;
	Coordinate *p = new Coordinate[maxLen];

	front = rear = p;
	//	topological sort
	for (int i = 0; i < _WIDTH; i++)
	{
		for (int j = 0; j < _HEIGHT; j++)
		{
			int x = i << 1 | 1;
			int y = j << 1 | 1;
			Coordinate cur(x, y);
			Coordinate suc;

			if (mazeMap[x][y].type() == WAY)
			{
				int cnt = 0;
				for (int k = 0; k < 4; k++)
				{
					suc = cur;
					suc = suc.add(fx[k], fy[k]);

					if (mazeMap[suc.x][suc.y].type() == EMPTY)
						++cnt;
				}

				if (cnt >= 3)
				{
					*rear = cur;
					rear++;
					if ((rear - p) == maxLen)
						rear = p;
				}
			}
		}
	}
	//test();
	while (front != rear)
	{
		BLOCK *cur = &(mazeMap[front->x][front->y]);
		BLOCK *suc = cur;
		Coordinate sucCor;

		for (int i = 0; i < 4; i++)
		{
			int mx = fx[i] + front->x;
			int my = fy[i] + front->y;
			if (mazeMap[mx][my].type() != EMPTY)
			{
				suc = &(mazeMap[mx][my]);
				sucCor = Coordinate(mx, my);
				break;
			}
		}
		
		if (cur->blockParrent == cur)
			suc->setParrent(suc);
		else cur->init(-1, EMPTY, _BLACK);

		int cnt = 0;
		for (int k = 0; k < 4; k++)
		{
			int mx = fx[k] + sucCor.x;
			int my = fy[k] + sucCor.y;
			if (mazeMap[mx][my].type() == EMPTY)
				++cnt;
		}

		if (cnt >= 3)
		{
			*rear = sucCor;
			rear++;
			if ((rear - p) == maxLen)
				rear = p;
		}
		

#ifndef _UNDER_TEST
		show();
#endif // _UNDER_TEST

		--_BACKS;
		if (_BACKS == 0)break;
		front++;
	}
}

//	判断点是否在地图内，是则返回 1
bool MazeCreator::isInMap(const Coordinate &cur)
{
	return cur.x > 0 && cur.y > 0 && cur.x < width && cur.y < height;
}