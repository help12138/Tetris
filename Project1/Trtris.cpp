// ��������Χ����
#include "Trtris.h"
#include<iostream>
#include <time.h>
#include<conio.h>
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
	// ���̲���
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
	putimage(0, 0, &imgBg); // ���Ʊ���ͼƬ

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

	curBlock->draw(leftMargin, topMargin);  // ��ǰ������Ⱦ
	nextBlock->draw(689, 150);  // Ԥ�淽��λ��
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
	bakBlock = *curBlock;  // ͨ����ֵ���캯��������ֵ������
	curBlock->drop();

	if (!curBlock->blockInMap(map)) {
		// �̻�����
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
	// ��ֹ�����ƶ������߽��Լ�λ���Ƿ�Ϸ�
	if (!curBlock->blockInMap(map)) {
		*curBlock = bakBlock;
	}
}


Trtris::~Trtris()
{
}

