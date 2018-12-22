#pragma once

#include "Array2D.h"
#include "CONSTS.h"
#include "Coordinate.h"
#include "Color.h"
#include "BLOCK.h"

class Room {

	public:

	Room();
//	���һ������ʵ��
	void randomRoom();
//	�ж��ص�
//	bool isCollasped(const Room &other);

	bool isCollasped(Array2D *_mazeMap);
	void show();
	bool isNotValid();

	void formInMap(Array2D *_mazeMap);

	private:

//	x/y ӦΪ����
	int x, y;
//	����ĳ��� ҲӦΪ����
	int width, height;
	Color roomColor;

//	��������Ľ�����
//	void calRoomArr(Coordinate *_arr, Coordinate &vec);

};

Room::Room()
{
	randomRoom();
}

void Room::randomRoom()
{
	roomColor.rand();

	x = randomBetween(1, (_CANVAS_WIDTH - 1) >> 1) * 2 - 1;
	y = randomBetween(1, (_CANVAS_HEIGHT - 1) >> 1) * 2 - 1;

	while (TRUE)
	{
		width = randomBetween(_ROOM_MIN_WIDTH >> 1, _ROOM_MAX_WIDTH >> 1);
		height = randomBetween(_ROOM_MIN_WIDTH >> 1, _ROOM_MAX_WIDTH >> 1);
		width = width << 1 | 1;
		height = height << 1 | 1;
		if (width*_RATE <= height && height*_RATE <= width) break;
	}

}

/*
bool Room::isCollasped(const Room &other)
{
	Coordinate roomArr1[4], roomArr2[4];

	Coordinate pos1(x, y), pos2(width - 1, height - 1);
	roomArr1[0] = pos1;
	calRoomArr(roomArr1, pos2);

	
	pos1.init(other.x, other.y);
	pos2.init(other.width - 1, other.height - 1);
	roomArr2[0] = pos1;
	calRoomArr(roomArr2, pos2);

//	��ⷿ���Ƿ���һ���Ǳ������ڱ�ķ�����
	int isIncludeTimes, flg = 0;
	for (int i = 0; i < 4; i++)
	{
		isIncludeTimes = 0;
		Coordinate bin = roomArr1[i];
		for (int j = 0; j < 4; j++)
		{
			Coordinate base = roomArr2[(j + 1) % 4] - roomArr2[j];
			int crossProduct = base.crossProduct(bin - roomArr2[j]);

			//	���С�����򷿼�ĸõ��� base �������Ҳ࣬��������һ���������
			if (crossProduct < 0) break;
			else if (crossProduct == 0)
			{
				//	���Ϊ�㵫�㲢δ����һ�������������(������ֱ����)
				if (!base.isInclude(bin - roomArr2[j])) break;
			}
			isIncludeTimes++;
		}
		//	��һ�����ڷ������������ɷ�����ԭ�з����ͻ
		if (isIncludeTimes == 4)
		{
			flg = 1;
			break;
		}
	}

	return flg;
}
*/

bool Room::isCollasped(Array2D *_mazeMap)
{
	for (int i = x; i < x + width; i++)
	{
		for (int j = y; j < y + height; j++)
		{
			if ((*_mazeMap)[i][j].type() == ROOM) return TRUE;
		}
	}
	return FALSE;
}

/*
void Room::calRoomArr(Coordinate *_arr, Coordinate &vec)
{
	for (int i = 0; i < 3; ++i)
	{
		_arr[i + 1] = _arr[i] + vec * _DIR[i];
	}
}
*/

void Room::show()
{
	Coordinate pos(x, y), vec(width, height);
	pos.show();
	vec.show();
}

bool Room::isNotValid()
{
	bool flg = 0;
	flg |= (x + width) >= _CANVAS_WIDTH;
	flg |= (y + height) >= _CANVAS_HEIGHT;
	return flg;
}

void Room::formInMap(Array2D *_mazeMap)
{
	BLOCK *_parrent = &((*_mazeMap)[x][y]);
	_parrent->init(NULL, ROOM, roomColor);
	for (int i = x; i < x + width; i++)
	{
		for (int j = y; j < y + height; j++)
		{
			(*_mazeMap)[i][j].setParrent(_parrent);
		}
	}
}