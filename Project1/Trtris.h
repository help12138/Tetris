#pragma once
class Trtris
{
public:
	Trtris() = default;
	Trtris(int rows, int cols, int left, int top, int blockSize);
	void init(); // 初始化
	void play(); // 游玩游戏
	~Trtris();

private:

};

Trtris::Trtris()
{
}



Trtris::~Trtris()
{
}