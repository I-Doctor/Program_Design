/*************************************************************************
    > File Name: shape.cpp
	> Orgnization:Tsinghua University
    > Author: 钟凯 2015011158
    > Mail: ZK14115@163.com 
    > Created Time: 2016.7.7 星期四
 ************************************************************************/
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

	HANDLE  out=GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	DWORD len;
	for(int i=0;i<4;i++)
	{
		if(position[i].row-3>0)
		{
			pos.X=2*(position[i].column+1);
			pos.Y=position[i].row-3;
			FillConsoleOutputCharacter(out,L' ',2,pos,&len);
		}
	}
	for(int i=0;i<4;i++)
	{
		if(position[i].row-3>0)
		{
			pos.X=2*(position[i].column);
			pos.Y=position[i].row-3;
			SetConsoleCursorPosition(out,pos);
			cout<<"■";
		}
		pos.X=0;
		pos.Y=HEIGHT-3;
		SetConsoleCursorPosition(out,pos);
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

	HANDLE  out=GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	DWORD len;
	for(int i=0;i<4;i++)
	{
		if(position[i].row-3>0)
		{
			pos.X=2*(position[i].column-1);
			pos.Y=position[i].row-3;
			FillConsoleOutputCharacter(out,L' ',2,pos,&len);
		}
	}
	for(int i=0;i<4;i++)
	{
		if(position[i].row-3>0)
		{
			pos.X=2*(position[i].column);
			pos.Y=position[i].row-3;
			SetConsoleCursorPosition(out,pos);
			cout<<"■";
		}
		pos.X=0;
		pos.Y=HEIGHT-3;
		SetConsoleCursorPosition(out,pos);
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
	/*重新打印*/
	HANDLE  out=GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	DWORD len;
	for(int i=0;i<4;i++)
	{
		if(position[i].row>4)
		{
			pos.X=2*(position[i].column);
			pos.Y=position[i].row-4;
			FillConsoleOutputCharacter(out,L' ',2,pos,&len);
		}
	}
	for(int i=0;i<4;i++)
	{
		if(position[i].row>3)
		{
			pos.X=2*(position[i].column);
			pos.Y=position[i].row-3;
			SetConsoleCursorPosition(out,pos);
			cout<<"■";
		}
	}
	pos.X=0;
	pos.Y=HEIGHT-3;
	SetConsoleCursorPosition(out,pos);
	return 1;
}
//打印出下一个图形
void Shape::PrintNext()
{
	HANDLE  out=GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;

	for(int i=3;i<7;i++)
	{
		pos.X=2*(WIDTH+1);
		pos.Y=i;
		SetConsoleCursorPosition(out,pos);
		cout<<"         ";
	}
	for(int i=0;i<4;i++)
	{		
		pos.X=2*((position[i].column+WIDTH)-3);
		pos.Y=position[i].row+3;
		SetConsoleCursorPosition(out,pos);
		cout<<"■";
	}
	pos.X=0;
	pos.Y=HEIGHT-3;
	SetConsoleCursorPosition(out,pos);
	//tiaoshi
//	cout<<"next over";
}
//确定旋转后的打印范围
void Shape::PrintRotate(Table& table)
{
	if(position[3].column-position[0].column==3||position[0].row-position[3].row==3
		||(position[0].column-position[3].column==3)||(position[3].row-position[0].row==3))
	{
		PrintNearby(2,table);
	}
	else
	{
		PrintNearby(1,table);
	}
}
//打印旋转后的范围
void Shape::PrintNearby(int n,Table& table)
{
	Position check;
	HANDLE  out=GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	for(int i=-n;i<=n;i++)
	{
		for(int j=-n;j<=n;j++)
		{
			check.column=position[2].column+j;
			check.row=position[2].row+i;
			if(check.column>0&&check.column<WIDTH-1&&check.row<HEIGHT-1&&check.row>3)
			{
				pos.X=2*(check.column);
				pos.Y=check.row-3;
				SetConsoleCursorPosition(out,pos);
				cout<<"  ";
				if(table.Check(check))
				{
					SetConsoleCursorPosition(out,pos);
					cout<<"■";
				}			
				for(int k=0;k<4;k++)
				{
					if((position[k].row==check.row)&&(position[k].column==check.column))
					{
						SetConsoleCursorPosition(out,pos);
						cout<<"■";
					}
				}
			}
		}
	}
	pos.X=0;
	pos.Y=HEIGHT-3;
	SetConsoleCursorPosition(out,pos);
}