#pragma once
#include<vector>
#include "Block.h"
#include <graphics.h>

using namespace std;
class Trtris
{
public:
	Trtris(int rows, int cols, int left, int top, int blockSize);
	void init(); // ��ʼ��
	void play(); // ������Ϸ
	~Trtris();

private:
	// ˽�к���
	void keyEvent();
	void updataWindow();
	int getDelay(); // ���ϴεĺ������õĺ�����
	void drop();
	void clearLine();
private:
	//˽�����ݳ�Ա
	int delay;
	bool update; // �Ƿ����
	// ��ͼ����
	vector<vector<int>> map;
	int rows;
	int cols;
	int leftMargin;
	int topMargin;
	int blockSize;
	IMAGE imgBg;

	Block* curBlock;
	Block* nextBlock; // Ԥ�淽��
};

