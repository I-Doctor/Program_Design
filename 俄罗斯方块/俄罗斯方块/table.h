#pragma once
//#include"shape.h"
#include"struct.h"
#include<iostream>
#include<windows.h>
#define HEIGHT 25
#define WIDTH 14

using namespace std;
class Shape;

class Table//��Ϸ���࣬��ʼ��Ϸ�����
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
	bool Check(Position& position);//����ĳλ���Ƿ�ɴ�
	int Remove();//��Ⲣ�����У������ֵȼ��ӷ֣��̶������
	Shape* CreatNew();//�����·��飬�������
	bool ReachTop();//����Ƿ���Ϸ�������̶�����á�������߷�����

	//�����û������
//	void operator +(Position p)	{	}
	friend Table Add(Table,Shape*);
	void Newtable();
	void Printfixedtable();
//	void PrintRotate(Shape*);
};