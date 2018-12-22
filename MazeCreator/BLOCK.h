#pragma once

#include "CONSTS.h"
#include "Color.h"

/*
	BLOCK类
	迷宫由 BLOCKS 构成，每个 BLOCK 有 类型/颜色 两种属性
*/


class BLOCK
{
	public:

	BLOCK();
	void setParrent(BLOCK *_blockParrent);
	BLOCK(const int & _blockId, const int &_blockType, const Color &_blockColor);
	void init(const int & _blockId, const int &_blockType, const Color &_blockColor);
	//	输出该 BLOCK 的 类型/颜色 属性
	void show();
	int id();
	int type();
	Color color();
	bool operator==(const BLOCK &other);

	private:

	int blockId;
	int blockType;
	Color blockColor;
	BLOCK *blockParrent;

	BLOCK *getParrent();

};

BLOCK::BLOCK()
{
}

void BLOCK::setParrent(BLOCK *_blockParrent)
{
	if (_blockParrent == NULL) _blockParrent = this;
	blockParrent = _blockParrent;
}

BLOCK::BLOCK(const int & _blockId, const int &_blockType, const Color &_blockColor)
{
	init(_blockId, _blockType, _blockColor);
}

void BLOCK::init(const int & _blockId, const int &_blockType, const Color &_blockColor)
{
	if (_blockId != NULL) blockId = _blockId;
	blockType = _blockType;
	blockColor = _blockColor;
	blockParrent = this;
}

void BLOCK::show()
{
	/*
	getParrent();
	printf("{\"%s\",", _TILES[blockType]);
	blockColor.show();
	putchar('}');
	*/
	getParrent();
	blockColor.show();
}

int BLOCK::id()
{
	getParrent();
	return blockId;
}

int BLOCK::type()
{
	getParrent();
	return blockType;
}

Color BLOCK::color()
{
	getParrent();
	return blockColor;
}

bool BLOCK::operator==(const BLOCK &other)
{
	getParrent();
	return blockType == other.blockType;
}

BLOCK *BLOCK::getParrent()
{
	if (this == blockParrent) return this;
	BLOCK *_parrent = blockParrent->getParrent();
	blockId = _parrent->blockId;
	blockType = _parrent->blockType;
	blockColor = _parrent->blockColor;
	blockParrent = _parrent;
	return _parrent;
}