// 创建方块的类
#include "Block.h"
#include <stdlib.h>

Block::Block()
{	
	// 七种方块的排布
	int block[7][4] = {
		1,3,5,7,  // I
		2,4,5,7,  // Z 1 型
		3,5,4,6,  // Z 2型
		3,5,4,7,  // T 型
		2,3,5,7,  // L
		3,5,7,6,  // J
		2,3,4,5   // 田
	};
	// 随机生成一种俄罗斯方块
	blockType = 1 + rand() % 7;

	// 初始化 方块
	for (int i = 0; i < 4; i++)
	{
		int value = block[blockType - 1][i];
		smallBlock[i].row = value / 2; // 初始小方块位于的行数
		smallBlock[i].col = value % 2; // 初始小方块位于的列数
	}
}

void Block::drop()
{
	// 下降
}

void Block::moveLeftRight(int offset) {
	// 左移和右移

}

void Block::retate()
{
	// 旋转
}

void Block::draw(int leftMargin, int topMargin)
{
	// 边框
}

Block::~Block()
{
}
