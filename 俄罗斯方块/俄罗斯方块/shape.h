#pragma once
#include"struct.h"
#include"table.h"
#include<iostream>
#include<windows.h>

using namespace std;
class Table;

class Shape//������
{
protected:
	Position position[4];//�ĸ�С��������
	State state;
	bool MoveCheck(Direction);//����Ƿ�����ĳ�����ƶ����˶������е���
public:
/*	Shape()
	{
		for(int i=0;i<4;i++)
		{
			position[i].column=1;
			position[i].row=1;
		}
		state=NORTH;
	}*///	friend Table operator +(){}//�̶��˶����飬down���׺����
	Position GetPosition(int n)
	{
		return position[n];
	}
	void Left(Table&);//�����ƶ�
	void Right(Table&);//�����ƶ�
	bool Down(Table&);//�����ƶ���һ�������Զ�����һ��
	virtual void Rotate(){}//��ת������������
	virtual ~Shape(){}

	void PrintNext();
	void PrintRotate(Table&);//��ת����ã������ת��Χ
	void PrintNearby(int,Table&);//��鲢��ӡ��Χ��С��Χ��bool=1�Ǵ�Χ
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