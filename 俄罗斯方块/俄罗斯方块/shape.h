#include<iostream>
#pragma once
using namespace std;

enum Direction//运动方向枚举
{
	LEFT,
	RIGHT,
	DOWN
};

enum State//朝向枚举
{
	NORTH,
	EAST,
	WEST,
	SOUTH
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
	void Left();//向左移动
	void Right();//向右移动
	void Down();//向下移动，一个周期自动运行一次
	virtual void Rotate();//旋转，按类型重载
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