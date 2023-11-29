#pragma once
#include <graphics.h>
#include<vector>

using namespace std;

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
	static IMAGE** getImage();

	Block& operator= (const Block& other);
	
	bool blockInMap(const vector<vector<int>>&map);

	void solidify(vector<vector<int>>& map);

	~Block();

private:
	int blockType;
	Point smallBlock[4];
	IMAGE *img;

	static IMAGE* imgs[7];
	static int size;
};

