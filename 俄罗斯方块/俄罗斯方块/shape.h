#pragma once
#include<iostream>
#include"table.h"
#include"game.h"
using namespace std;

enum Direction//运动方向枚举
{
	LEFT =0,
	RIGHT =1,
	DOWN =2
};

enum State//朝向枚举
{
	NORTH =0,
	EAST =1,
	SOUTH =2,
	WEST =3
};

struct Position//坐标数据
{
	unsigned int row;
	unsigned int column;
};

class Shape//方块类
{
protected:
	Position position[4];//四个小方块坐标
	State state;
	bool MoveCheck(Direction);//检测是否能向某方向移动，运动函数中调用
public:
	Shape()
	{
		for(int i=0;i<4;i++)
		{
			position[i].column=1;
			position[i].row=1;
		}
		state=NORTH;
	}
	friend Table operator +(Table& table,Shape& shape)
	{
	}//固定运动方块，down到底后调用
	void Left();//向左移动
	void Right();//向右移动
	void Down();//向下移动，一个周期自动运行一次
	virtual void Rotate();//旋转，按类型重载
	virtual ~Shape();
};

class ShapeI : public Shape
{
public:
	void Rotate()
	{
		if(state==NORTH||state==SOUTH)
		{
			for(int i=0;i<4;i++)
			{
				position[i].row=position[3].row;
				position[i].column=position[3].column+(3-i);
			}
		}
		else
		{
			for(int i=0;i<4;i++)
			{
				position[i].column=position[3].column;
				position[i].row=position[3].row-(3-i);
			}
		}
		state=(State)(state+1);
	}
	ShapeI()
	{
		for(int i=0;i<4;i++)
		{
			position[i].row =i;
			position[i].column =6;
		}
	}
};

class ShapeT : public Shape
{
public:
	void Rotate();
	ShapeT();
};

class ShapeL : public Shape
{
public:
	void Rotate();
	ShapeL();
};

class ShapeJ : public Shape
{
public:
	void Rotate();
	ShapeJ();
};

class ShapeZ : public Shape
{
public:
	void Rotate();
	ShapeZ();
};

class ShapeS : public Shape
{
public:
	void Rotate();
	ShapeS();
};

class ShapeO : public Shape
{
public:
	void Rotate();
	ShapeO();
};