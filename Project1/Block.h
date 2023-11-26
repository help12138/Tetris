#pragma once
#include <graphics.h>

struct Point
{
	// ÿ��С���������λ��
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
	IMAGE *img;

	static IMAGE* imgs[7];
	static int size;
};

