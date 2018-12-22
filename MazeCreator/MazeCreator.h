#pragma once

#include "CONSTS.h"

#include "Array2D.h"

#include "BLOCK.h"

#include "Room.h"

#include <ctime> 
#include <vector>

/*
	�Թ�������

	MazeCreator	��ʼ���Թ�����
	init		���Թ����д
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
		/*
		std::vector<Room>::iterator inf, sup, itr;
		inf = roomList.begin();
		sup = roomList.end();
		for (itr = inf; itr < sup; itr++)
		{
			itr->show();
			putchar('\n');
		}
		*/

		/*
		putchar('\n');
		mazeMap.show();
		*/

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
	Array2D mazeMap;
	vector <Room> roomList;

	void generateRoom();
	void generateWays();

};

MazeCreator::MazeCreator()
{
//	������������Ա������·�ͷ���
	srand((unsigned)time(NULL));

	width = _CANVAS_WIDTH;
	height = _CANVAS_HEIGHT;
	roomList.clear();
	generate();
}

void MazeCreator::generate()
{
//	�ÿհ׷����ʼ�� MazeMap	
	mazeMap.init(width, height);

	roomList.clear();
	generateRoom();
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

void MazeCreator::generateRoom()
{
	//	���ϳ������ɷ���
	Room base;
	show();
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
		show();
	}
}

void MazeCreator::generateWays()
{

}