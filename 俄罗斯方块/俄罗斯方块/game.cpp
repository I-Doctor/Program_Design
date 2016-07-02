#include"struct.h"
#include"shape.h"
#include"game.h"
#include"table.h"

#include<iostream>
#include<iomanip>
#include<conio.h>
#include<windows.h>

using namespace std;
//_————打印菜单——
void Game::PrintMenu()
{
	system("CLS");
	cout<<"-------------------------------"<<endl;
	cout<<"****** 怀旧经典 老少皆宜 ******        当前玩家："<<endl;
	cout<<"-------------------------------        "<<currentPlayer.name<<endl;
	cout<<"@@@@@@     俄罗斯方块    @@@@@@"<<endl;
	cout<<endl;
	cout<<"1、新游戏"<<'\t'<<"2、继续游戏"<<'\t'<<"3、排行榜"<<endl;
	cout<<"4、选择玩家"<<'\t'<<"5、控制说明"<<'\t'<<"6、退出游戏"<<endl;
	cout<<"-----------------------------------------------------"<<endl;
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
	while(1)
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
				return;}
		}
	}
}
//————游戏核心————
void Game::Play()
{
//	cout<<"tiaoshi play"<<endl;
//	system("pause");
	clock_t clocklast,clocknow;
	clocklast=clock();

	currenttable=Add(fixedtable,currentshape);//更新动态屏幕
	currenttable.Fresh();//动态刷新屏幕
	while(1)
	{
		//查询时间并检测
		clocknow=clock();               
		if(clocknow-clocklast>=0.6 * CLOCKS_PER_SEC)
		{
			clocklast=clocknow;
			if(currentshape->Down(fixedtable))
			{
				currenttable=Add(fixedtable,currentshape);
				currenttable.Fresh();
			}
			else
			{
				fixedtable=Add(fixedtable,currentshape);
				delete currentshape;
				fixedtable.Fresh();//刷新屏幕
				fixedtable.Remove();
				fixedtable.Fresh();//刷新屏幕
				if(fixedtable.ReachTop()){return ;}
				else{currenttable=fixedtable;currentshape=NewShape();currenttable.Fresh();}//刷新屏幕
			}
//+++			currenttable=fixedtable+*(currentshape);
		}

		//处理按键
		if(_kbhit())//处理按键
		{
			switch(_getch())
			{
			case 'w':
			case 'W':
			case '8':
			case 72://上
				{
					currentshape->Rotate();
					for(int i=0;i<4;i++)
					{
						if(fixedtable.Check(currentshape->GetPosition(i)))
						{
							currentshape->Rotate();
							currentshape->Rotate();
							currentshape->Rotate();
							break;
						}
					}
					currenttable=Add(fixedtable,currentshape);
					currenttable.Fresh();//动态刷新屏幕
				break;
				}
			case 'a':
			case 'A':
			case '4':
			case 75://左
				currentshape->Left(fixedtable);
				currenttable=Add(fixedtable,currentshape);
				currenttable.Fresh();//动态刷新屏幕
				break;
			case 'S':
			case 's':
			case '2':
			case 80://下
				{
					if(currentshape->Down(fixedtable))
					{
						currenttable=Add(fixedtable,currentshape);
						currenttable.Fresh();
					}
					else
					{
						fixedtable=Add(fixedtable,currentshape);
						delete currentshape;
						fixedtable.Fresh();//刷新屏幕
						fixedtable.Remove();
						fixedtable.Fresh();//刷新屏幕
						if(fixedtable.ReachTop()){return ;}
						else{currenttable=fixedtable;currentshape=NewShape();currenttable.Fresh();}//刷新屏幕
					}
					break;
				}
			case 'D':
			case 'd':
			case '6':
			case (char)(77)://右
				{
					currentshape->Right(fixedtable);
					currenttable=Add(fixedtable,currentshape);
					*(currentshape);
					currenttable.Fresh();//动态刷新屏幕
					break;
				}
			default:
				{
					if(Pause())//暂停、返回1表示退出
					{
						return ;
					}
				}

			}
//+++			currenttable=fixedtable+*(currentshape);
		}
//tiaoshi
//	system("pause");
	}
}
//————显示玩家列表————
void List::ShowList()
{
	cout<<"名次"<<"      "<<"名字"<<"       "<<"分数"<<endl;
	Player* outputplayer=head;
	for(int i=0;i<nodenumber;i++)
	{
		if(outputplayer!=NULL)
		{
			cout<<"  "<<i+1<<"       "<<setiosflags(ios::left)<<setw(12)<<outputplayer->name
				<<setiosflags(ios::left)<<setw(4)<<outputplayer->score<<endl;
			outputplayer=outputplayer->next;
		}
		else{break;}
	}
}
//————选择玩家————
void Game::ChoosePlayer()
{
	int choose;
	system("CLS");
	cout<<"当前玩家："<<'\t'<<currentPlayer.name<<endl;
	cout<<"请输入序号选择玩家，或输入0新建"<<endl;
	playerlist.ShowList();
	cin>>choose;
	if(choose<=playerlist.nodenumber&&choose>0)
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
	else if(choose==0)//新建
	{
		while(1)
		{
			cout<<"请输入姓名(10字符以内)：";
			cin>>currentPlayer.name;
			for(int i=0;i<10;i++)                          //检查是否超限
			{
				if(currentPlayer.name[i]=='\0')               //未超限
				{
					Player** addplayer=&(playerlist.head);
					for(int j=0;;j++)
					{
						if(*(addplayer)!=NULL)
						{
							addplayer=&((*(addplayer))->next);
						}
						else
						{
							(*(addplayer))=new Player;
							(*(*(addplayer)))=currentPlayer;
							playerlist.nodenumber+=1;
							break;
						}
					}
					return;
				}
			}
			                               //for中未退出，说明超限
			cout<<"用户名过长，   "<<endl;
			currentPlayer.name[0]='n';
			currentPlayer.name[1]='o';
			currentPlayer.name[2]=' ';
			currentPlayer.name[3]='p';
			currentPlayer.name[4]='l';
			currentPlayer.name[5]='a';
			currentPlayer.name[6]='y';
			currentPlayer.name[7]='e';
			currentPlayer.name[8]='r';
			currentPlayer.name[10]=0;
		}
	}
	else
	{
		cout<<"输入错误，请重新输入"<<endl;
		clock_t start;
		start=clock();
		while(1)
		{
			if((clock()-start)>=(2*CLOCKS_PER_SEC))
			{break;}
		}
		ChoosePlayer();
	}
//	cout<<"tiaoshi 选择结束";
}
//————新游戏————
void Game::NewGame()
{
	
	ChoosePlayer();
//	cout<<"tiaoshi"<<endl;
	while(1)
	{
		cout<<"1、开始新游戏	2、返回主菜单"<<endl;
		int newgame;
		cin>>newgame;
		if(newgame==1)
		{
//deletetiaoshi			delete currentshape;
			currentshape=NewShape();
			fixedtable.Newtable();
			//	cout<<"tiaoshi"<<endl;
			Play();
		}
		else
		{break;}
	}
}
//————从保存的开始，继续游戏————
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
//————在屏幕上方生成新的方块
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
	for(unsigned int i=0;i<choosestate;i++)
	{shape->Rotate();}
//	cout<<"tiaoshi:"<<shape->GetPosition(2).row<<"  "<<shape->GetPosition(2).row<<endl;
//	cout<<"  ";
	return shape;
}
//————排行榜
void Game::RankList()
{
	cout<<"———————————"<<endl;
	cout<<"@@@	   排行榜	  @@@"<<endl;
	cout<<"———————————"<<endl;
	playerlist.ShowList();
	system("pause");
}
//————显示操作方法
void Game::ShowOperations()
{
	system("CLS");
	cout<<"—————————————"<<endl;
	cout<<"@@@	    控制说明 	  @@@"<<endl;
	cout<<"—————————————"<<endl;
	cout<<" W : 旋转"<<endl;
	cout<<" A : 左移"<<endl;
	cout<<" D : 右移"<<endl;
	cout<<" S : 下降"<<endl;
	cout<<" 其它：暂停"<<endl;
	system("pause");
}
//————暂停后调用进行选择
bool Game::Pause()
{
	system("CLS");
	cout<<"已暂停，请选择："<<endl;
	cout<<"1、继续游戏		2、保存并退出"<<endl;
	int pausechoose;
	cin>>pausechoose;
	if(pausechoose==1)
	{return 0;}
	else
	{return 1;}
}

void Game::Screen()
{
	cout<<"----------------------------------"<<endl;
	cout<<"    ||当前分数： "<<currentPlayer.score<<endl;
	currenttable.Fresh();
	cout<<"----------------------------------"<<endl;
	cout<<"    ||当前分数： "<<currentPlayer.score<<endl;
	cout<<nextshape->Shownext;
}