#pragma once
class Block
{
public:
	Block()= default;
	void drop();
	void moveLeftRight(int offset);
	void retate();
	void draw(int leftMargin, int topMargin);
	~Block();

private:

};

Block::Block()
{
}


void Block::drop()
{
}

Block::~Block()
{
}