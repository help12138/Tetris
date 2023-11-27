// ��������Χ����
#include "Trtris.h"
#include <time.h>
#include <stdlib.h>

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
		vector<int> mapRow;
		for (int j = 0; i < cols; j++) {
			mapRow.push_back(0);
		}
		map.push_back(mapRow);
	}
}

void Trtris::init()
{
	// ��ʼ��
	delay = 30;
	//  �����������
	srand(time(NULL));
}

void Trtris::play()
{
	// ��ʼ��Ϸ
	init();

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

