#include<iostream>
#include<iomanip>
#include<conio.h>
#include"game.h"
using namespace std;
//_————打印菜单——
void PrintMenu()
{
	system("CLS");
	cout<<"-------------------------------"<<endl;
	cout<<"****** 怀旧经典 老少皆宜 ******"<<endl;
	cout<<"-------------------------------"<<endl;
	cout<<"@@@@@@     俄罗斯方块    @@@@@@"<<endl;
	cout<<endl;
	cout<<"1、新游戏"<<'\t'<<"2、继续游戏"<<'\t'<<"3、排行榜"<<endl;
	cout<<"4、选择玩家"<<'\t'<<"5、控制说明"<<'\t'<<"6、退出游戏"<<endl;
}
//————运行游戏程序——读取数据并判断
void Game::Run()
{
	//Read();
	Welcome();
}
//————菜单选择————
void Game::Welcome()
{
	PrintMenu();
	unsigned int menuChoice;
	cin>>menuChoice;
	switch(menuChoice)
	{
	case 1:{NewGame();break;}
	case 2:{Continue();break;}
	case 3:{RankList();break;}
	case 4:{ChoosePlayer();break;}
	case 5:{ShowOperations();break;}
	default:{
		//Save();
		clock_t start;
		start=clock();
		cout<<"BYE-BYE!";
		while(1)
		{
			if((clock()-start)>=(2*CLOCKS_PER_SEC))
			{break;}
		}
			}
	}
}
//————游戏核心————
void Game::Play()
{
	clock_t clocklast,clocknow;
	clocklast=clock();
	while(1)
	{
		currenttable.Fresh();//刷新屏幕
		clocknow=clock();               //查询时间并检测
		if(clocknow-clocklast>=0.45F * CLOCKS_PER_SEC)
		{
			clocklast=clocknow;
			currentshape->Down();
			currenttable=fixedtable+*(currentshape);
		}
		if(_kbhit())//处理按键
		{
			switch(_getch())
			{
			case 'w':
			case 'W':
			case 8:
			case 72://上
				currentshape->Rotate();
				break;
			case 'a':
			case 'A':
			case 4:
			case 75://左
				currentshape->Left();
				break;
			case 'S':
			case 's':
			case 2:
			case 80://下
				currentshape->Down();
				break;
			case 'D':
			case 'd':
			case 6:
			case 77://右
				currentshape->Right();
				break;
			default:Pause();//暂停
			}
			currenttable=fixedtable+*(currentshape);
		}
//tiaoshi
//	system("pause");
	}
}
//————显示排行榜————
void List::ShowList()
{
	cout<<"@@	排行榜	@@"<<endl;
	cout<<"名次"<<"  "<<"名字"<<"		"<<"分数"<<endl;
	Player* outputplayer=head;
	for(int i=0;i<nodenumber;i++)
	{
		if(outputplayer!=NULL)
		{
			cout<<i+1<<"  "<<setiosflags(ios::left)<<setw(10)<<outputplayer->name
				<<setiosflags(ios::left)<<setw(4)<<outputplayer->score;
			outputplayer=outputplayer->next;
		}
		else{break;}
	}
}
//————选择玩家————
void Game::ChoosePlayer()
{
	int choose;
	cout<<"请输入序号选择下列玩家或输入0新建玩家"<<endl;
	playerlist.ShowList();
	cin>>choose;
	if(choose<playerlist.nodenumber&&choose>0)
	{
		Player* chooseplayer=playerlist.head;
		for(int i=0;i<choose;i++)
		{
			if(chooseplayer!=NULL)
			{
				(currentPlayer)=*(chooseplayer);
				chooseplayer=chooseplayer->next;
			}
			else{break;}
		}
		currentPlayer.next=NULL;
	}
	else if(choose==0)
	{
		cout<<"请输入姓名(10字符以内)：";
		cin>>currentPlayer.name;
	}
	else
	{
		cout<<"输入错误，请重新输入"<<endl;
		ChoosePlayer();
	}
}
//
void Game::NewGame()
{
	ChoosePlayer();
	currentshape=NewShape();
	Play();
}

void Game::Continue()
{
	if(pause)
	{
		pause=0;
		Play();
	}
	else
	{
		int choose;
		cout<<"没有存档，开始新游戏？"<<endl;
		cout<<""<<endl;
		cin>>choose;
		if(choose==1)
		{
			NewGame();
		}
	}
}

Shape* Game::NewShape()
{
	srand((unsigned)time(NULL));
	unsigned int chooseshape=rand()%7;
	Shape* shape;
	switch(chooseshape)
	{
	case 0:	shape=new ShapeI;break;
	case 1:	shape=new ShapeL;break;
	case 2:	shape=new ShapeJ;break;
	case 3:	shape=new ShapeS;break;
	case 4:	shape=new ShapeZ;break;
	case 5:	shape=new ShapeO;break;
	case 6:	shape=new ShapeT;break;
	default:cout<<"error game.cpp.NewShape";
	}

	srand((unsigned)time(NULL));
	unsigned int choosestate=rand()%4;
	for(;;)
	{};

	return shape;
}
