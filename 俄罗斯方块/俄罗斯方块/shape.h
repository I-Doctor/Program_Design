#pragma once
#include"struct.h"
#include"table.h"
#include<iostream>
#include<windows.h>

using namespace std;
class Table;

class Shape//方块类
{
protected:
	Position position[4];//四个小方块坐标
	State state;
	bool MoveCheck(Direction);//检测是否能向某方向移动，运动函数中调用
public:
/*	Shape()
	{
		for(int i=0;i<4;i++)
		{
			position[i].column=1;
			position[i].row=1;
		}
		state=NORTH;
	}*///	friend Table operator +(){}//固定运动方块，down到底后调用
	Position GetPosition(int n)
	{
		return position[n];
	}
	void Left(Table&);//向左移动
	void Right(Table&);//向右移动
	bool Down(Table&);//向下移动，一个周期自动运行一次
	virtual void Rotate(){}//旋转，按类型重载
	virtual ~Shape(){}

	void PrintNext();
	void PrintRotate(Table&);//旋转后调用，检测旋转范围
	void PrintNearby(int,Table&);//检查并打印大范围或小范围，bool=1是大范围
	friend Table Add(Table,Shape*);
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
				position[i].row=position[2].row;
				position[i].column=position[2].column+(2-i);
			}
		}
		else
		{
			for(int i=0;i<4;i++)
			{
				position[i].column=position[2].column;
				position[i].row=position[2].row-(2-i);
			}
		}
		state=(State)((state+1)%4);
	}
	ShapeI()
	{
		for(int i=0;i<4;i++)
		{
			position[i].row =i;
			position[i].column =6;
		}
		state=NORTH;
	}
	~ShapeI(){};
};

class ShapeT : public Shape
{
public:
	void Rotate()
	{
		position[1]=position[0];
		position[0]=position[3];
		switch(state)
		{
		case NORTH:
			{
				position[3].column=position[2].column;
				position[3].row=position[2].row+1;
				break;
			}
		case EAST:
			{
				position[3].column=position[2].column-1;
				position[3].row=position[2].row;
				break;
			}
		case SOUTH:
			{
				position[3].column=position[2].column;
				position[3].row=position[2].row-1;
				break;
			}
		case WEST:
			{
				position[3].column=position[2].column+1;
				position[3].row=position[2].row;
				break;
			}
		}
		state=(State)((state+1)%4);
	}
	ShapeT()
	{
		position[0].column=6;
		position[0].row=1;
		for(int i=1;i<4;i++)
		{
			position[i].row=2;
			position[i].column=(4+i);
		}
		state=NORTH;
	}
	~ShapeT(){};
};

class ShapeL : public Shape
{
public:
	void Rotate()
	{
		switch(state)
		{
		case NORTH:
			{
				position[0].column-=2;

				position[1].column-=1;
				position[1].row-=1;

				position[3].column+=1;
				position[3].row+=1;
				break;
			}
		case EAST:
			{
				position[0].row-=2;

				position[1].column+=1;
				position[1].row-=1;

				position[3].column-=1;
				position[3].row+=1;
				break;
			}
		case SOUTH:
			{
				position[0].column+=2;

				position[1].column+=1;
				position[1].row+=1;

				position[3].column-=1;
				position[3].row-=1;
				break;
			}
		case WEST:
			{
				position[0].row+=2;

				position[1].column-=1;
				position[1].row+=1;

				position[3].column+=1;
				position[3].row-=1;
				break;
			}
		}
		state=(State)((state+1)%4);
	}
	ShapeL()
	{
		position[0].column=7;
		position[0].row=3;

		for(int i=1;i<4;i++)
		{
			position[i].column=6;
			position[i].row=4-i;
		}
		state=NORTH;
	}
	~ShapeL(){};
};

class ShapeJ : public Shape
{
public:
	void Rotate()
	{
		switch(state)
		{
		case NORTH:
			{
				position[0].row-=2;

				position[1].column-=1;
				position[1].row-=1;

				position[3].column+=1;
				position[3].row+=1;
				break;
			}
		case EAST:
			{
				position[0].column+=2;

				position[1].column+=1;
				position[1].row-=1;

				position[3].column-=1;
				position[3].row+=1;
				break;
			}
		case SOUTH:
			{
				position[0].row+=2;

				position[1].column+=1;
				position[1].row+=1;

				position[3].column-=1;
				position[3].row-=1;
				break;
			}
		case WEST:
			{
				position[0].column-=2;

				position[1].column-=1;
				position[1].row+=1;

				position[3].column+=1;
				position[3].row-=1;
				break;
			}
		}
		state=(State)((state+1)%4);
	}
	ShapeJ()
	{
		position[0].column=6;
		position[0].row=3;
		for(int i=1;i<4;i++)
		{
			position[i].column=7;
			position[i].row=4-i;
		}
		state=NORTH;
	}
	~ShapeJ(){};
};

class ShapeZ : public Shape
{
public:
	void Rotate()
	{
		position[3]=position[1];
		switch(state)
		{
		case NORTH:
			{
				position[0].row-=2;
				position[1].column+=1;
				position[1].row+=1;
				break;
			}
		case EAST:
			{
				position[0].column+=2;
				position[1].column-=1;
				position[1].row+=1;
				break;
			}
		case SOUTH:
			{
				position[0].row+=2;
				position[1].column-=1;
				position[1].row-=1;
				break;
			}
		case WEST:
			{
				position[0].column-=2;
				position[1].column+=1;
				position[1].row-=1;
				break;
			}
		}
		state=(State)((state+1)%4);
	}
	ShapeZ()
	{
		position[0].column=6;
		position[0].row=3;

		position[1].column=7;
		position[1].row=1;

		position[2].column=7;
		position[2].row=2;

		position[3].column=6;
		position[3].row=2;

		state=NORTH;
	}
	~ShapeZ(){};
};

class ShapeS : public Shape
{
public:
	void Rotate()
	{
		position[3]=position[1];
		switch(state)
		{
		case NORTH:
			{
				position[0].row+=2;
				position[1].column+=1;
				position[1].row+=1;
				break;
			}
		case EAST:
			{
				position[0].column-=2;
				position[1].column-=1;
				position[1].row+=1;
				break;
			}
		case SOUTH:
			{
				position[0].row-=2;
				position[1].column-=1;
				position[1].row-=1;
				break;
			}
		case WEST:
			{
				position[0].column+=2;
				position[1].column+=1;
				position[1].row-=1;
				break;
			}
		}
		state=(State)((state+1)%4);
	}
	ShapeS()
	{
		position[0].column=8;
		position[0].row=1;

		position[1].column=7;
		position[1].row=1;

		position[2].column=7;
		position[2].row=2;

		position[3].column=6;
		position[3].row=2;

		state=NORTH;
	}
	~ShapeS(){};

};

class ShapeO : public Shape
{
public:
	void Rotate(){}
	ShapeO()
	{
		position[0].column=position[2].column=6;
		position[1].column=position[3].column=7;

		position[0].row=position[1].row=1;
		position[2].row=position[3].row=2;
	}
	~ShapeO(){};
};