// 创建方框范围的类
#include "Trtris.h"
#include <time.h>
#include <stdlib.h>

Trtris::Trtris(int rows, int cols, int left, int top, int blockSize)
{
	//构造函数 创建页面
}

void Trtris::init()
{
	// 初始化
	delay = 30;
	//  方块随机生成
	srand(time(NULL));
}

void Trtris::play()
{
	// 开始游戏
	init();

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

}

int Trtris::getDelay()
{
	return 0;
}

void Trtris::drop()
{
}

void Trtris::clearLine()
{
}

Trtris::Trtris()
{
}



Trtris::~Trtris()
{
}

