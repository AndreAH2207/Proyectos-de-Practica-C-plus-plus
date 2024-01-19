#pragma once
#include <iostream>

#define WIDTH 120
#define HEIGHT 30

using namespace std;
using namespace System;

class Items
{
protected:

	int x;
	int y;
	int dx;
	int dy;
	int width;
	int height;
	int ID;
	int color;

public:
	Items(int x, int y): x(x), y(y) {}

	~Items()
	{}

	virtual void draw() {};

	bool move()
	{
		if (x + dx < 0 || x + dx + width > WIDTH)
		{
			dx *= -1;
		}

		if (y + dy < 0 || y + dy + height > HEIGHT)
		{
			dy *= -1;
			return true;
		}
		x += dx ;
		y += dy ;
		return false;
	}

		void clear()
		{
			for (int i = 0; i < height; i++)
			{
				for (int j = 0; j < width; j++)
				{
					Console::SetCursorPosition(x + j, y + i);
					cout << " ";
				}
			}
		}

	int getX() { return x; }
	int getY() { return y; }
	int getDx() { return dx; }
	int getDy() { return dy; }
	int getWidth() { return width; }
	int getHeight() { return height; }
	int getID() { return ID; }

};
