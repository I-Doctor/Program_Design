
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
	HANDLE  out=GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	DWORD len;
	for(int i=0;i<4;i++)
	{
		pos.X=2*(position[i].column+1);
		pos.Y=position[i].row-3;
		FillConsoleOutputCharacter(out,L' ',2,pos,&len);
	}
	for(int i=0;i<4;i++)
	{
		pos.X=2*(position[i].column);
		pos.Y=position[i].row-3;
		SetConsoleCursorPosition(out,pos);
		cout<<"��";
		pos.X=0;
		pos.Y=HEIGHT-3;
		SetConsoleCursorPosition(out,pos);
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

	HANDLE  out=GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	DWORD len;
	for(int i=0;i<4;i++)
	{
		pos.X=2*(position[i].column-1);
		pos.Y=position[i].row-3;
		FillConsoleOutputCharacter(out,L' ',2,pos,&len);
	}
	for(int i=0;i<4;i++)
	{
		pos.X=2*(position[i].column);
		pos.Y=position[i].row-3;
		SetConsoleCursorPosition(out,pos);
		cout<<"��";
		pos.X=0;
		pos.Y=HEIGHT-3;
		SetConsoleCursorPosition(out,pos);
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
	/*���´�ӡ*/
	HANDLE  out=GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	DWORD len;
	for(int i=0;i<4;i++)
	{
		pos.X=2*(position[i].column);
		pos.Y=position[i].row-4;
		FillConsoleOutputCharacter(out,L' ',2,pos,&len);
	}
	for(int i=0;i<4;i++)
	{
		pos.X=2*(position[i].column);
		pos.Y=position[i].row-3;
		SetConsoleCursorPosition(out,pos);
		cout<<"��";
		pos.X=0;
		pos.Y=HEIGHT-3;
		SetConsoleCursorPosition(out,pos);
	}
	return 1;
}

void Shape::PrintNext()
{
	HANDLE  out=GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;

	for(int i=3;i<7;i++)
	{
		pos.X=2*(WIDTH+4);
		pos.Y=i;
		SetConsoleCursorPosition(out,pos);
		cout<<"        ";
	}
	for(int i=0;i<4;i++)
	{		
		pos.X=2*((position[i].column+WIDTH)-3);
		pos.Y=position[i].row+3;
		SetConsoleCursorPosition(out,pos);
		cout<<"��";
	}
	pos.X=0;
	pos.Y=HEIGHT-3;
	SetConsoleCursorPosition(out,pos);
}

void Shape::PrintRotate(Table& table)
{
	if(position[3].column-position[0].column==2||position[0].row-position[3].row==2
		||(position[0].column-position[3].column==2)||(position[3].row-position[0].row==2))
	{
		PrintNearby(2,table);
	}
	else
	{
		PrintNearby(1,table);
	}
}

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
			pos.X=2*(check.column);
			pos.Y=check.row-3;
			SetConsoleCursorPosition(out,pos);
			cout<<"  ";
			if(table.Check(check))
			{
				SetConsoleCursorPosition(out,pos);
				cout<<"��";
			}			
			for(int k=0;k<4;k++)
			{
				if((position[k].row==check.row)&&(position[k].column==check.column))
				{
					SetConsoleCursorPosition(out,pos);
					cout<<"��";
				}
			}
		}
	}
}