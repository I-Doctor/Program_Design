#include"struct.h"
#include"shape.h"
#include"game.h"
#include"table.h"

#include<iostream>
#include<iomanip>
#include<conio.h>
#include<windows.h>

using namespace std;
//_����������ӡ�˵�����
void Game::PrintMenu()
{
	system("CLS");
	cout<<"-------------------------------"<<endl;
	cout<<"****** ���ɾ��� ���ٽ��� ******        ��ǰ��ң�"<<endl;
	cout<<"-------------------------------        "<<currentPlayer.name<<endl;
	cout<<"@@@@@@     ����˹����    @@@@@@"<<endl;
	cout<<endl;
	cout<<"1������Ϸ"<<'\t'<<"2��������Ϸ"<<'\t'<<"3�����а�"<<endl;
	cout<<"4��ѡ�����"<<'\t'<<"5������˵��"<<'\t'<<"6���˳���Ϸ"<<endl;
	cout<<"-----------------------------------------------------"<<endl;
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
//����������Ϸ���ġ�������
void Game::Play()
{
//	cout<<"tiaoshi play"<<endl;
//	system("pause");
	clock_t clocklast,clocknow;
	clocklast=clock();

	currenttable=Add(fixedtable,currentshape);//���¶�̬��Ļ
	currenttable.Fresh();//��̬ˢ����Ļ
	while(1)
	{
		//��ѯʱ�䲢���
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
				fixedtable.Fresh();//ˢ����Ļ
				fixedtable.Remove();
				fixedtable.Fresh();//ˢ����Ļ
				if(fixedtable.ReachTop()){return ;}
				else{currenttable=fixedtable;currentshape=NewShape();currenttable.Fresh();}//ˢ����Ļ
			}
//+++			currenttable=fixedtable+*(currentshape);
		}

		//������
		if(_kbhit())//������
		{
			switch(_getch())
			{
			case 'w':
			case 'W':
			case '8':
			case 72://��
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
					currenttable.Fresh();//��̬ˢ����Ļ
				break;
				}
			case 'a':
			case 'A':
			case '4':
			case 75://��
				currentshape->Left(fixedtable);
				currenttable=Add(fixedtable,currentshape);
				currenttable.Fresh();//��̬ˢ����Ļ
				break;
			case 'S':
			case 's':
			case '2':
			case 80://��
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
						fixedtable.Fresh();//ˢ����Ļ
						fixedtable.Remove();
						fixedtable.Fresh();//ˢ����Ļ
						if(fixedtable.ReachTop()){return ;}
						else{currenttable=fixedtable;currentshape=NewShape();currenttable.Fresh();}//ˢ����Ļ
					}
					break;
				}
			case 'D':
			case 'd':
			case '6':
			case (char)(77)://��
				{
					currentshape->Right(fixedtable);
					currenttable=Add(fixedtable,currentshape);
					*(currentshape);
					currenttable.Fresh();//��̬ˢ����Ļ
					break;
				}
			default:
				{
					if(Pause())//��ͣ������1��ʾ�˳�
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
//����������ʾ����б�������
void List::ShowList()
{
	cout<<"����"<<"      "<<"����"<<"       "<<"����"<<endl;
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
//��������ѡ����ҡ�������
void Game::ChoosePlayer()
{
	int choose;
	system("CLS");
	cout<<"��ǰ��ң�"<<'\t'<<currentPlayer.name<<endl;
	cout<<"���������ѡ����ң�������0�½�"<<endl;
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
	else if(choose==0)//�½�
	{
		while(1)
		{
			cout<<"����������(10�ַ�����)��";
			cin>>currentPlayer.name;
			for(int i=0;i<10;i++)                          //����Ƿ���
			{
				if(currentPlayer.name[i]=='\0')               //δ����
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
			                               //for��δ�˳���˵������
			cout<<"�û���������   "<<endl;
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
		cout<<"�����������������"<<endl;
		clock_t start;
		start=clock();
		while(1)
		{
			if((clock()-start)>=(2*CLOCKS_PER_SEC))
			{break;}
		}
		ChoosePlayer();
	}
//	cout<<"tiaoshi ѡ�����";
}
//������������Ϸ��������
void Game::NewGame()
{
	
	ChoosePlayer();
//	cout<<"tiaoshi"<<endl;
	while(1)
	{
		cout<<"1����ʼ����Ϸ	2���������˵�"<<endl;
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
//���������ӱ���Ŀ�ʼ��������Ϸ��������
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
//������������Ļ�Ϸ������µķ���
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
//�����������а�
void Game::RankList()
{
	cout<<"����������������������"<<endl;
	cout<<"@@@	   ���а�	  @@@"<<endl;
	cout<<"����������������������"<<endl;
	playerlist.ShowList();
	system("pause");
}
//����������ʾ��������
void Game::ShowOperations()
{
	system("CLS");
	cout<<"��������������������������"<<endl;
	cout<<"@@@	    ����˵�� 	  @@@"<<endl;
	cout<<"��������������������������"<<endl;
	cout<<" W : ��ת"<<endl;
	cout<<" A : ����"<<endl;
	cout<<" D : ����"<<endl;
	cout<<" S : �½�"<<endl;
	cout<<" ��������ͣ"<<endl;
	system("pause");
}
//����������ͣ����ý���ѡ��
bool Game::Pause()
{
	system("CLS");
	cout<<"����ͣ����ѡ��"<<endl;
	cout<<"1��������Ϸ		2�����沢�˳�"<<endl;
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
	cout<<"    ||��ǰ������ "<<currentPlayer.score<<endl;
	currenttable.Fresh();
	cout<<"----------------------------------"<<endl;
	cout<<"    ||��ǰ������ "<<currentPlayer.score<<endl;
	cout<<nextshape->Shownext;
}