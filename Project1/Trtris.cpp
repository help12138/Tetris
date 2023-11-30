// 创建方框范围的类
#include "Trtris.h"
#include<iostream>
#include <time.h>
#include<conio.h>
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
	// 键盘操作
	unsigned char ch;
	bool rotateFalse = false;
	int dx = 0;
	if (_kbhit()) {
		ch = _getch();
		if (ch == 224) {
			ch = _getch();
			switch (ch)
			{
			case 72:
				rotateFalse = true;
				break;
			case 80:
				delay = SPEED_QUIK;
				break;
			case 75:
				dx = -1;
				break;
			case 77:
				dx = 1;
				break;
			default:
				break;
			}
		}
	}

	if (rotateFalse) {
		// to do
	}
	if (dx != 0) {
		moveLeftRight(dx);
		update = true;
	}
}

void Trtris::updataWindow() {
	putimage(0, 0, &imgBg); // 绘制背景图片

	IMAGE** imgs = Block::getImage();

	BeginBatchDraw();
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++) {
			if (map[i][j] == 0) continue;

			int x = j * blockSize + leftMargin;
			int y = i * blockSize + topMargin;
			putimage(x, y, imgs[map[i][j]-1]);
		}
	}

	curBlock->draw(leftMargin, topMargin);  // 当前方块渲染
	nextBlock->draw(689, 150);  // 预告方块位置
	EndBatchDraw();
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
	bakBlock = *curBlock;  // 通过赋值构造函数将对象赋值给变量
	curBlock->drop();

	if (!curBlock->blockInMap(map)) {
		// 固化方块
		bakBlock.solidify(map);
		delete curBlock;
		curBlock = nextBlock;
		nextBlock = new Block;
	}

	delay = SPEED_NORMAL;
}

void Trtris::clearLine()
{
}

void Trtris::moveLeftRight(int offset)
{
	bakBlock = *curBlock;
	curBlock->moveLeftRight(offset);
	// 防止左右移动超过边界以及位置是否合法
	if (!curBlock->blockInMap(map)) {
		*curBlock = bakBlock;
	}
}


Trtris::~Trtris()
{
}

