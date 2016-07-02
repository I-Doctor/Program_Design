#include"struct.h"
#include"shape.h"
#include<windows.h>

using namespace std;
//�жϲ�ִ������
void Shape::Left(Table& table)//�����ƶ�
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
//�жϲ�ִ������
void Shape::Right(Table& table)//�����ƶ�
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
//�жϲ�ִ�����ƣ�����1Ϊ���Ƴɹ�������0Ϊ������
bool Shape::Down(Table& table)//�����ƶ���һ�������Զ�����һ��
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