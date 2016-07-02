#include"struct.h"
#include"shape.h"
#include<windows.h>

using namespace std;
//判断并执行左移
void Shape::Left(Table& table)//向左移动
{
	for(int i=0;i<4;i++)
	{
		position[i].column-=1;
	}
	for(int i=0;i<4;i++)
	{
		if(table.Check(position[i]))
		{
			for(int j=0;j<4;j++)
			{
				position[j].column+=1;
			}
			return;
		}
	}
}
//判断并执行右移
void Shape::Right(Table& table)//向右移动
{
	for(int i=0;i<4;i++)
	{
		position[i].column+=1;
	}
	for(int i=0;i<4;i++)
	{
		if(table.Check(position[i]))
		{
			for(int j=0;j<4;j++)
			{
				position[j].column-=1;
			}
			return;
		}
	}
}
//判断并执行下移，返回1为下移成功，返回0为到底了
bool Shape::Down(Table& table)//向下移动，一个周期自动运行一次
{
	for(int i=0;i<4;i++)
	{
		position[i].row+=1;
	}
	for(int i=0;i<4;i++)
	{
		if(table.Check(position[i]))
		{
			for(int j=0;j<4;j++)
			{
				position[j].row-=1;
			}
			return 0;
		}
	}
	return 1;
}

void Shape::Shownext()
{
	
}