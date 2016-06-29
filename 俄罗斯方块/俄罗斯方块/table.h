#pragma once
#include<iostream>
#include"shape.h"
#define HEIGHT 25
#define WIDTH 14

using namespace std;

class Table//��Ϸ�����࣬��ʼ��Ϸ�����
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
	void Remove();//��Ⲣ�����У������ֵȼ��ӷ֣��̶������
	Shape* CreatNew();//�����·��飬�������
	void ReachTop();//����Ƿ���Ϸ�������̶�����á�������߷�����
	friend Table& operator +(Table& table,Shape& shape);//�̶��˶����飬down���׺����
	void Fresh();
};