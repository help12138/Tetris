// 创建方块的类
#include "Block.h"
#include <stdlib.h>

IMAGE* Block::imgs[7] = { NULL , };
int Block::size = 36;

Block::Block()
{	
	if (imgs[0] == NULL) {
		IMAGE imgTmp;
		loadimage(&imgTmp, "../tiles.png");

		SetWorkingImage(&imgTmp);
		for (int i = 0; i < 7; i++)
		{
			imgs[i] = new IMAGE;
			getimage(imgs[i], i*size, 0, size, size);
		}
		SetWorkingImage(); //恢复工作区
	}
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

	img = imgs[blockType - 1];
}

void Block::drop()
{
	// 下降
	for (auto &block : smallBlock) {
		block.row++;
	}
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
	// 方块绘制
	for (int i = 0; i < 4; i++)
	{
		int x = leftMargin + smallBlock[i].col * size;
		int y = topMargin + smallBlock[i].row * size;
		putimage(x, y, img);
	}
}

IMAGE** Block::getImage()
{

	return imgs;
}

Block& Block::operator=(const Block& other)
{
	// 赋值构造函数
	if (this == &other) return *this;

	this->blockType = other.blockType;
	for (int i = 0; i < 4; i++)
	{
		this->smallBlock[i] = other.smallBlock[i];
	}
	return *this;
}

bool Block::blockInMap(const vector<vector<int>>& map)
{
	// 判断方块是否超出边界
	int rows = map.size();
	int cols = map[0].size();
	for (int i = 0; i < 4; i++)
	{
		if (smallBlock[i].col < 0 || smallBlock[i].col >= cols ||
			smallBlock[i].row < 0 || smallBlock[i].row >= rows ||
			map[smallBlock[i].row][smallBlock[i].col] != 0) {
			return false;
		}
	}
}

void Block::solidify(vector<vector<int>>& map)
{
	for (int i = 0; i < 4; i++) {
		map[smallBlock[i].row][smallBlock[i].col] = blockType;
	}
}

Block::~Block()
{
}
