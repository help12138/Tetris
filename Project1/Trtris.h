#pragma once
class Trtris
{
public:
	Trtris();
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
};

