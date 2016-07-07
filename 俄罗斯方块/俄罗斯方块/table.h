#pragma once
//#include"shape.h"
#include"struct.h"
#include<iostream>
#include<windows.h>
#define HEIGHT 25
#define WIDTH 14

using namespace std;
class Shape;

class Table//游戏池类，开始游戏后调用
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
	int Remove();//检测并消除行，包含分等级加分，固定后调用
	Shape* CreatNew();//产生新方块，检查后调用
	bool ReachTop();//检测是否游戏结束，固定后调用、包含最高分提醒

	//运算符没有重载
//	void operator +(Position p)	{	}
	friend Table Add(Table,Shape*);
	void Newtable();
	void Printfixedtable();
//	void PrintRotate(Shape*);
};