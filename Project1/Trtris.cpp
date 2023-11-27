// ��������Χ����
#include "Trtris.h"
#include<iostream>
#include <time.h>
#include <stdlib.h>


const int SPEED_NORMAL = 500;
const int SPEED_QUIK = 50;

Trtris::Trtris(int rows, int cols, int left, int top, int blockSize)
{
	//���캯�� ����ҳ��
	this->rows = rows;
	this->cols = cols;
	this->leftMargin = left;
	this->topMargin = top;
	this->blockSize = blockSize;
	for (int i = 0; i < rows; i++)
	{
		// mapRow ������ʾ���������
		vector<int> mapRow;
		for (int j = 0; j < cols; j++) {
			mapRow.push_back(0);
		}
		map.push_back(mapRow);
	}
}

void Trtris::init()
{
	// ��ʼ��
	delay = SPEED_NORMAL;
	//  �����������
	srand(time(NULL));
	// ��������
	initgraph(938, 896);
	// ���ر���ͼƬ
	loadimage(&imgBg, "../bg2.png");

	// ���³�ʼ����Ϸ���е�����
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
	
	// ��ʼ��Ϸ
	init();

	nextBlock = new Block;
	curBlock = nextBlock;
	nextBlock = new Block;

	int timer = 0;  // ��ʱ��
	while (1)
	{
		// �����û�����
		keyEvent();

		timer += getDelay();

		if (timer > delay) {
			timer = 0;
			drop();
			update = true;
		}

		if (update) {
			update = false;
			// ��Ⱦ��Ϸ����
			updataWindow();

			// ������Ϸ����
			clearLine();
		}
	}
}

void Trtris::keyEvent()
{

}

void Trtris::updataWindow() {
	putimage(0, 0, &imgBg); // ���Ʊ���ͼƬ

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

