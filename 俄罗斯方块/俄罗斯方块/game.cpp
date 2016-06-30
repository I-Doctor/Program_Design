#include<iostream>
#include<iomanip>
#include<conio.h>
#include"game.h"
using namespace std;
//_����������ӡ�˵�����
void PrintMenu()
{
	system("CLS");
	cout<<"-------------------------------"<<endl;
	cout<<"****** ���ɾ��� ���ٽ��� ******"<<endl;
	cout<<"-------------------------------"<<endl;
	cout<<"@@@@@@     ����˹����    @@@@@@"<<endl;
	cout<<endl;
	cout<<"1������Ϸ"<<'\t'<<"2��������Ϸ"<<'\t'<<"3�����а�"<<endl;
	cout<<"4��ѡ�����"<<'\t'<<"5������˵��"<<'\t'<<"6���˳���Ϸ"<<endl;
}
//��������������Ϸ���򡪡���ȡ���ݲ��ж�
void Game::Run()
{
	//Read();
	Welcome();
}
//���������˵�ѡ�񡪡�����
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
//����������Ϸ���ġ�������
void Game::Play()
{
	clock_t clocklast,clocknow;
	clocklast=clock();
	while(1)
	{
		currenttable.Fresh();//ˢ����Ļ
		clocknow=clock();               //��ѯʱ�䲢���
		if(clocknow-clocklast>=0.45F * CLOCKS_PER_SEC)
		{
			clocklast=clocknow;
			currentshape->Down();
			currenttable=fixedtable+*(currentshape);
		}
		if(_kbhit())//������
		{
			switch(_getch())
			{
			case 'w':
			case 'W':
			case 8:
			case 72://��
				currentshape->Rotate();
				break;
			case 'a':
			case 'A':
			case 4:
			case 75://��
				currentshape->Left();
				break;
			case 'S':
			case 's':
			case 2:
			case 80://��
				currentshape->Down();
				break;
			case 'D':
			case 'd':
			case 6:
			case 77://��
				currentshape->Right();
				break;
			default:Pause();//��ͣ
			}
			currenttable=fixedtable+*(currentshape);
		}
//tiaoshi
//	system("pause");
	}
}
//����������ʾ���а񡪡�����
void List::ShowList()
{
	cout<<"@@	���а�	@@"<<endl;
	cout<<"����"<<"  "<<"����"<<"		"<<"����"<<endl;
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
//��������ѡ����ҡ�������
void Game::ChoosePlayer()
{
	int choose;
	cout<<"���������ѡ��������һ�����0�½����"<<endl;
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
		cout<<"����������(10�ַ�����)��";
		cin>>currentPlayer.name;
	}
	else
	{
		cout<<"�����������������"<<endl;
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
		cout<<"û�д浵����ʼ����Ϸ��"<<endl;
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
