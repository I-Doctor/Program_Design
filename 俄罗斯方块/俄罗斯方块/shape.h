#pragma once
#include<iostream>
#include"table.h"
#include"game.h"
using namespace std;

enum Direction//�˶�����ö��
{
	LEFT =0,
	RIGHT =1,
	DOWN =2
};

enum State//����ö��
{
	NORTH =0,
	EAST =1,
	SOUTH =2,
	WEST =3
};

struct Position//��������
{
	unsigned int row;
	unsigned int column;
};

class Shape//������
{
protected:
	Position position[4];//�ĸ�С��������
	State state;
	bool MoveCheck(Direction);//����Ƿ�����ĳ�����ƶ����˶������е���
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
	}//�̶��˶����飬down���׺����
	void Left();//�����ƶ�
	void Right();//�����ƶ�
	void Down();//�����ƶ���һ�������Զ�����һ��
	virtual void Rotate();//��ת������������
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