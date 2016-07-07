#include"struct.h"
#include"table.h"
#include"shape.h"
#include<conio.h>
#include<iostream>
#include<windows.h>

using namespace std;
//检查坐标处是否有1，返回1为有
bool Table::Check(Position& position)
{
	return t[position.row][position.column];
}
//刷新游戏池
/*
void Table::Fresh()
{
	system("CLS");
	for(int i=4;i<HEIGHT-1;i++)
	{
		cout<<"    "<<"□";
		for(int j=1;j<WIDTH-1;j++)
		{
			Position position;
			position.row=i;
			position.column=j;
			if(Check(position)==0){cout<<"  ";}
			else{cout<<"□";}■
		}
		cout<<"□";
		cout<<endl;
	}
	cout<<"    ";
	for(int j=0;j<WIDTH;j++)
	{cout<<"□";}
}
*/
//落地后调用，检测是否消除一行，返回消除行数
int Table::Remove()
{
	int rownumber=0;
	for(int i=4;i<HEIGHT-1;i++)
	{
		bool flag=1;
		for(int j=1;j<WIDTH-1;j++)
		{
			if(t[i][j]==0)
			{flag=0;break;}
		}
		if(flag==1)
		{
			HANDLE  out=GetStdHandle(STD_OUTPUT_HANDLE);
			COORD pos;
			DWORD len;
			rownumber++;
			for(int k=i;k>3;k--)
			{
				pos.X=2;
				pos.Y=k-3;
				FillConsoleOutputCharacter(out,L' ',2*(WIDTH-2),pos,&len);
				for(int l=1;l<WIDTH-1;l++)
				{
					t[k][l]=t[k-1][l];
					if(t[k][l])
					{
						pos.X=2*(l);
						pos.Y=(k-3);
						SetConsoleCursorPosition(out,pos);
						cout<<"■";
					}
				}
			}
			pos.X=0;
			pos.Y=HEIGHT-3;
			SetConsoleCursorPosition(out,pos);
		}
	}
	if(rownumber<5)
	{return rownumber;	}
	else
	{
		cerr<<"remove error!"<<endl;
		system("pause");
		return 0;
	}
}
//检测是否结束，返回1为结束
bool Table::ReachTop()
{
	for(int i=1;i<13;i++)
	{
		if(!t[3][i]){}
		else
		{
			system("CLS");
			cout<<"    ***GAME OVER!***"<<endl;
			return 1;
		}
	}
	return 0;
}
//将shape加到table上
Table Add(Table table,Shape* shape)
{
	for(int i=0;i<4;i++)
	{
		table.t[shape->position[i].row][shape->position[i].column]=1;
	}
	return table;
}
//生成新table
void Table::Newtable()
{
	
	for(int i=0;i<HEIGHT-1;i++)
	{
		t[i][0]=1;
		for(int j=1;j<WIDTH-1;j++)
		{t[i][j]=0;}
		t[i][WIDTH-1]=1;
	}
	for(int j=0;j<WIDTH;j++)
	{t[HEIGHT-1][j]=1;}
}

void Table::Printfixedtable()
{
	HANDLE  out=GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;

	for(int i=4;i<HEIGHT-1;i++)
	{		
		for(int j=1;j<WIDTH-1;j++)
		{
			if(t[i][j])
			{
				pos.X=2*j;	
				pos.Y=i-3;
				SetConsoleCursorPosition(out,pos);
				cout<<"■";
			}
		}
	}
	pos.X=0;
	pos.Y=HEIGHT-3;
	SetConsoleCursorPosition(out,pos);
}