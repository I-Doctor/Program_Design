#include<iostream>
#pragma once
using namespace std;

enum Direction//�˶�����ö��
{
	LEFT,
	RIGHT,
	DOWN
};

enum State//����ö��
{
	NORTH,
	EAST,
	WEST,
	SOUTH
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
	void Left();//�����ƶ�
	void Right();//�����ƶ�
	void Down();//�����ƶ���һ�������Զ�����һ��
	virtual void Rotate();//��ת������������
	virtual ~Shape();
	friend Table& operator +(Table& table,Shape& shape);
};

class ShapeI : public Shape
{
public:
	void Rotate();
	ShapeI();
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