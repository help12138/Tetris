// �����������
#include "Block.h"
#include <stdlib.h>

Block::Block()
{	
	// ���ַ�����Ų�
	int block[7][4] = {
		1,3,5,7,  // I
		2,4,5,7,  // Z 1 ��
		3,5,4,6,  // Z 2��
		3,5,4,7,  // T ��
		2,3,5,7,  // L
		3,5,7,6,  // J
		2,3,4,5   // ��
	};
	// �������һ�ֶ���˹����
	blockType = 1 + rand() % 7;

	// ��ʼ�� ����
	for (int i = 0; i < 4; i++)
	{
		int value = block[blockType - 1][i];
		smallBlock[i].row = value / 2; // ��ʼС����λ�ڵ�����
		smallBlock[i].col = value % 2; // ��ʼС����λ�ڵ�����
	}
}

void Block::drop()
{
	// �½�
}

void Block::moveLeftRight(int offset) {
	// ���ƺ�����

}

void Block::retate()
{
	// ��ת
}

void Block::draw(int leftMargin, int topMargin)
{
	// �߿�
}

Block::~Block()
{
}
