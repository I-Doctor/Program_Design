#pragma once
#include<iostream>
#include"shape.h"
#define HEIGHT 25
#define WIDTH 14

using namespace std;

class Table//游戏界面类，开始游戏后调用
{
private:
	bool t[HEIGHT][WIDTH];
public:
	Table()
	{
		for(int i=0;i<HEIGHT-1;i++)
		{
			t[i][0]=t[i][WIDTH-1]=1;
			for(int j=1;j<WIDTH;j++)
			{
				t[i][j]=0;
			}
		}
	}
	bool Check(Position& position);//返回某位置是否可达
	void Remove();//检测并消除行，包含分等级加分，固定后调用
	Shape* CreatNew();//产生新方块，检查后调用
	void ReachTop();//检测是否游戏结束，固定后调用、包含最高分提醒
	friend Table& operator +(Table& table,Shape& shape);//固定运动方块，down到底后调用
	void Fresh();
};