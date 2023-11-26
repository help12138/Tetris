#pragma once

struct Point
{
	// 每个小方块的行列位置
	int row;
	int col;
};

class Block
{
public:
	Block();
	void drop();
	void moveLeftRight(int offset);
	void retate();
	void draw(int leftMargin, int topMargin);
	~Block();

private:
	int blockType;
	Point smallBlock[4];
};

