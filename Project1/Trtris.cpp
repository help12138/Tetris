// 创建方框范围的类
#include "Trtris.h"
#include<iostream>
#include <time.h>
#include <stdlib.h>


const int SPEED_NORMAL = 500;
const int SPEED_QUIK = 50;

Trtris::Trtris(int rows, int cols, int left, int top, int blockSize)
{
	//构造函数 创建页面
	this->rows = rows;
	this->cols = cols;
	this->leftMargin = left;
	this->topMargin = top;
	this->blockSize = blockSize;
	for (int i = 0; i < rows; i++)
	{
		// mapRow 用来表示方块的种类
		vector<int> mapRow;
		for (int j = 0; j < cols; j++) {
			mapRow.push_back(0);
		}
		map.push_back(mapRow);
	}
}

void Trtris::init()
{
	// 初始化
	delay = SPEED_NORMAL;
	//  方块随机生成
	srand(time(NULL));
	// 创建窗口
	initgraph(938, 896);
	// 加载背景图片
	loadimage(&imgBg, "../bg2.png");

	// 重新初始化游戏区中的数据
	char data[20][10];
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++) {
			map[i][j] = 0;
		}
	}

}

void Trtris::play()
{
	
	// 开始游戏
	init();

	nextBlock = new Block;
	curBlock = nextBlock;
	nextBlock = new Block;

	int timer = 0;  // 定时器
	while (1)
	{
		// 接受用户输入
		keyEvent();

		timer += getDelay();

		if (timer > delay) {
			timer = 0;
			drop();
			update = true;
		}

		if (update) {
			update = false;
			// 渲染游戏画面
			updataWindow();

			// 更改游戏数据
			clearLine();
		}
	}
}

void Trtris::keyEvent()
{

}

void Trtris::updataWindow() {
	putimage(0, 0, &imgBg); // 绘制背景图片

	curBlock->draw(leftMargin, topMargin);
	nextBlock->draw(689, 150);
}

int Trtris::getDelay()
{
	static unsigned long long lastTime = 0;
	unsigned long long currentTime =  GetTickCount();

	if (lastTime == 0) {
		lastTime = currentTime;
		return 0;
	}
	else {
		int ret = currentTime - lastTime;
		lastTime = currentTime;
		return ret;
	}
}

void Trtris::drop()
{
}

void Trtris::clearLine()
{
}


Trtris::~Trtris()
{
}

