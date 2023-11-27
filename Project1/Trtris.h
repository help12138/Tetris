#pragma once
#include<vector>
#include "Block.h"
#include <graphics.h>

using namespace std;
class Trtris
{
public:
	Trtris(int rows, int cols, int left, int top, int blockSize);
	void init(); // 初始化
	void play(); // 游玩游戏
	~Trtris();

private:
	// 私有函数
	void keyEvent();
	void updataWindow();
	int getDelay(); // 与上次的函数调用的毫秒间隔
	void drop();
	void clearLine();
private:
	//私有数据成员
	int delay;
	bool update; // 是否更新
	// 地图数据
	vector<vector<int>> map;
	int rows;
	int cols;
	int leftMargin;
	int topMargin;
	int blockSize;
	IMAGE imgBg;

	Block* curBlock;
	Block* nextBlock; // 预告方块
};

