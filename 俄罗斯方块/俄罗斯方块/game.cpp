/*************************************************************************
    > File Name: game.cpp
	> Orgnization:Tsinghua University
    > Author: �ӿ� 2015011158
    > Mail: ZK14115@163.com 
    > Created Time: 2016.7.7 ������
 ************************************************************************/
#include"struct.h"
#include"shape.h"
#include"game.h"
#include"table.h"

#include<cmath>
#include<iostream>
#include<fstream>
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
	//tiaoshi
	//cout<<currentPlayer.name;

}
//��������������Ϸ���򡪡���ȡ���ݲ��ж�
void Game::Run()
{
	Read();
	clock_t start;
	start=clock();
	while(1)
	{
		if((clock()-start)>=(2*CLOCKS_PER_SEC))
		{break;}
	}
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
			Save();
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
	int addscore=0;
/*	currenttable=Add(fixedtable,currentshape);
	currenttable.Fresh();
	*/

	while(1)
	{
		//��ѯʱ�䲢���
		clocknow=clock();               
		if(clocknow-clocklast>=level * CLOCKS_PER_SEC)
		{
			clocklast=clocknow;
		if(currentshape->Down(fixedtable)){}
			else
			{
				fixedtable=Add(fixedtable,currentshape);
				delete currentshape;
//				fixedtable.Fresh();//ˢ����Ļ
				addscore=fixedtable.Remove();
				if(addscore)
				{AddScore(addscore);}
				addscore=0;
//				fixedtable.Fresh();//ˢ����Ļ
				if(fixedtable.ReachTop())
				{return ;}
				else{currentshape=nextshape;nextshape=NewShape();nextshape->PrintNext();}//ˢ����Ļ
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
					currentshape->PrintRotate(fixedtable);//�ֲ�ˢ����ת
				break;
				}
			case 'a':
			case 'A':
			case '4':
			case 75://��
				currentshape->Left(fixedtable);
				break;
			case 'S':
			case 's':
			case '2':
			case 80://��
				{
					if(currentshape->Down(fixedtable)){}
					else
					{
						fixedtable=Add(fixedtable,currentshape);
						delete currentshape;
						addscore=fixedtable.Remove();
						if(addscore)
						{AddScore(addscore);}
						addscore=0;
						if(fixedtable.ReachTop()){return ;}
						else{currentshape=nextshape;nextshape=NewShape();nextshape->PrintNext();}//ˢ����Ļ
					}
					break;
				}
			case 'D':
			case 'd':
			case '6':
			case (char)(77)://��
				{
					currentshape->Right(fixedtable);
					break;
				}
			default:
				{
					if(Pause())//��ͣ������1��ʾ�˳�
					{return ;}
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
	/*������*/
	Player* sortplayer1=head;
	Player* sortplayer2;
	for(unsigned int i=1;i<nodenumber-1;i++)
	{
		sortplayer1=head;
		if(head==NULL)
		{}
		else
	{
		sortplayer2=head->next;
		if(head->score<head->next->score)
		{
				head->next=sortplayer2->next;
				head=sortplayer2;
				head->next=sortplayer1;
		}
		for(unsigned int j=1;j<(nodenumber-i);j++)
		{
			if(sortplayer2->score<sortplayer2->next->score )
			{
				sortplayer1->next=sortplayer2->next;
				sortplayer2->next=sortplayer2->next->next;
				sortplayer1->next->next=sortplayer2;
				sortplayer2=sortplayer1->next;
			}
			sortplayer1=sortplayer2;
			sortplayer2=sortplayer2->next;
		}
	}
	}
	/*�����*/
	cout<<"����"<<"      "<<"����"<<"       "<<"��߷���"<<endl;
	Player* outputplayer=head;
	for(unsigned int i=0;i<nodenumber;i++)
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
	unsigned int choose;
	system("CLS");
	cout<<"||ע�⣺�л���ҽ�ʧȥ��ǰ��ͣ����Ϸ||"<<endl;
	cout<<"��ǰ��ң�"<<'\t'<<currentPlayer.name<<endl;
	cout<<"���������ѡ����ң�����0�½�������-1����"<<endl;
	playerlist.ShowList();
	cin>>choose;
	if(choose<=playerlist.nodenumber&&choose>0)
	{
		Player* chooseplayer=playerlist.head;
		for(unsigned int i=1;i<choose;i++)
		{
			if(chooseplayer->next!=NULL)
			{
				chooseplayer=chooseplayer->next;
			}
			else{break;}
		}
		if(strcmp(currentPlayer.name,chooseplayer->name))
		{
			pause=0;
		}
		currentPlayer=*(chooseplayer);
		currentPlayer.next=NULL;
	}
	else if(choose==0)//�½�
	{
		while(1)
		{
			Player chooseplayer;
			cout<<"����������(10�ַ�����)��";
			cin>>chooseplayer.name;
			bool toolong=1;
			for(int i=0;i<10;i++)                          //����Ƿ���
			{
				if(chooseplayer.name[i]=='\0')               //δ����
				{
					toolong=0;
					Player* compareplayer=playerlist.head;                  //����Ƿ�����
					bool samename=0;
					for(int j=0;j<playerlist.nodenumber;j++)
					{
						if(!strcmp(chooseplayer.name,compareplayer->name))
						{samename=1;break;}
						compareplayer=compareplayer->next;
					}
					if(samename)
					{cout<<"�����Ѵ��ڣ�"<<endl;break;}
					//������
					Player** addplayer=&(playerlist.head);
					for(int j=0;;j++)
					{
						if(*(addplayer)!=NULL)
						{
							addplayer=&((*(addplayer))->next);
						}
						else//��������ҳɹ�
						{
							(*(addplayer))=new Player;
							(*(*(addplayer)))=chooseplayer;
							playerlist.nodenumber+=1;
							currentPlayer=chooseplayer;

							break;
						}
					}
					return;
				}
			}
			if(toolong)//����
			{
				cout<<"�û���������   "<<endl;
				chooseplayer.name[0]='n';
				chooseplayer.name[1]='o';
				chooseplayer.name[2]=' ';
				chooseplayer.name[3]='p';
				chooseplayer.name[4]='l';
				chooseplayer.name[5]='a';
				chooseplayer.name[6]='y';
				chooseplayer.name[7]='e';
				chooseplayer.name[8]='r';
				chooseplayer.name[10]='\0';
			}
		}
	}
	else if(choose==-1)
	{
		return;
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
	if((currentPlayer.name[0])=='n'&&
		currentPlayer.name[1]=='o'&&
		currentPlayer.name[2]==' '&&
		currentPlayer.name[3]=='p'&&
		currentPlayer.name[4]=='l'&&
		currentPlayer.name[5]=='a'&&
		currentPlayer.name[6]=='y'&&
		currentPlayer.name[7]=='e'&&
		currentPlayer.name[8]=='r')
	{ChoosePlayer();}
//	cout<<"tiaoshi"<<endl;
	while(1)
	{
		system("cls");
		cout<<"��ǰ��ң�"<<currentPlayer.name<<endl;
		cout<<"1����ʼ����Ϸ	2���������˵�"<<endl;
		int newgame;
		cin>>newgame;
		if(newgame==1)              //��ʼ����Ϸ�����ʼ��
		{
			pause=0;
			currentScore=oneRow=twoRow=threeRow=fourRow=0;
//deletetiaoshi			delete currentshape;
			currentshape=NewShape();
			nextshape=NewShape();
			fixedtable.Newtable();
			PrintScreen();
			nextshape->PrintNext();
//	cout<<"tiaoshi"<<endl;
			Play();
		}
		else
		{break;}
	}
}
//���������ӱ���Ŀ�ʼ��������Ϸ
void Game::Continue()
{
	if(pause)
	{
		pause=0;
		currentshape=NewShape();
		nextshape=NewShape();
		PrintScreen();
		fixedtable.Printfixedtable();
		nextshape->PrintNext();
		Play();
	}
	else
	{
		int choose;
		cout<<"û�д浵����ʼ����Ϸ��"<<endl;
		cout<<"   1.��    2.����     ";
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
//����������ӡ���а�
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
	HANDLE  out=GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X=0;
	pos.Y=HEIGHT-3;
	SetConsoleCursorPosition(out,pos);
	cout<<"����ͣ����ѡ��"<<endl;
	cout<<"1��������Ϸ    2�����沢�˳�  ";
	int pausechoose;
	cin>>pausechoose;
	if(pausechoose==1)
	{
		pos.X=0;
		pos.Y=HEIGHT-3;
		SetConsoleCursorPosition(out,pos);
		cout<<"                   "<<endl;
		pos.X=0;
		pos.Y=HEIGHT-2;
		SetConsoleCursorPosition(out,pos);    
		cout<<"                                  "<<endl;
		pos.X=0;
		pos.Y=HEIGHT-3;
		SetConsoleCursorPosition(out,pos);
		return 0;}
	else
	{
		pause=1;
		//tiaoshi
		Save();
		return 1;
	}
}
//����������ӡ��Ϸ������Ļ
void Game::PrintScreen()
{
	system("CLS");
	//������
	for(int j=0;j<WIDTH+10;j++){cout<<"��";}cout<<endl;   //������
	/*������*/
	cout<<"��                        ��   ����һͼ�Ρ�   ��"<<endl;
	/*�嵽ʮ��*/
	for(int i=5;i<11;i++)
	{cout<<"��                        ��                  ��"<<endl;}
	/*��11��*/
	cout<<"��                        ����������������������"<<endl;
	/*��12��*/
	cout<<"��                        ��   ����ǰ������   ��"<<endl;
	/*13�У�����*/
	cout<<"��                        ��         ";
	cout<<setiosflags(ios::left)<<setw(3)<<currentScore<<"      ��"<<endl;
	/*14*/
	cout<<"��                        ��                  ��"<<endl;
	/*��15~18��*/
	cout<<"��                        ��      1�У�";
	cout<<setw(3)<<oneRow;
	cout<<"    ��"<<endl;
	cout<<"��                        ��      2�У�";
	cout<<setw(3)<<twoRow;
	cout<<"    ��"<<endl;
	cout<<"��                        ��      3�У�";
	cout<<setw(3)<<threeRow;
	cout<<"    ��"<<endl;
	cout<<"��                        ��      4�У�";
	cout<<setw(3)<<fourRow;
	cout<<"    ��"<<endl;

/*	cout<<"��                        ��";
	cout<<setiosflags(ios::right)<<setw(10)<<"3�У�";
	cout<<setiosflags(ios::left)<<setw(8)<<twoRow;  cout<<"��"<<endl;
	cout<<"��                        ��";
	cout<<setiosflags(ios::right)<<setw(10)<<"3�У�";
	cout<<setiosflags(ios::left)<<setw(8)<<threeRow;  cout<<"��"<<endl;
	cout<<"��                        ��";
	cout<<setiosflags(ios::right)<<setw(10)<<"4�У�";
	cout<<setiosflags(ios::left)<<setw(8)<<fourRow;  cout<<"��"<<endl;
	*/
	/*19��*/
	cout<<"��                        ��                  ��"<<endl;
	/*20��*/
	cout<<"��                        ����������������������"<<endl;

	/*21~23*/
	cout<<"��                        �� ��ת��W  �½���S ��"<<endl;
	cout<<"��                        �� ���ƣ�A  ���ƣ�D ��"<<endl;
	cout<<"��                        ��       by:ZK      ��"<<endl;
	/*24*/
	cout<<"������������������������������������������������"<<endl;
}
//������������Ϸ��ʵʱ��ʾ����,�¼�¼����
void Game::AddScore(const int& n)
{
	currentScore+=(int)(pow(2,n));

	HANDLE  out=GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X=2*WIDTH+9;
	pos.Y=10;
	SetConsoleCursorPosition(out,pos);
	cout<<setiosflags(ios::left)<<setw(3)<<currentScore;
	if(currentScore>(currentPlayer.score))
	{
		pos.X=2*WIDTH+5;
		pos.Y=11;
		SetConsoleCursorPosition(out,pos);
		cout<<"�¼�¼��";
		Player* updateplayer=playerlist.head;
		for(unsigned int i=0;updateplayer!=NULL&&(i<playerlist.nodenumber);i++)
		{
			bool same=1;
			for(int j=0;(j<10)&&(updateplayer->name[j]!='\0');j++)
			{
				if(updateplayer->name[j]!=currentPlayer.name[j])
				{
					same=0;
					break;
				}
				else if(updateplayer->name[j]=='\0')
				{break;}
			}

			if(same==1)
			{
				updateplayer->score=currentPlayer.score=currentScore;
				break;
			}
			else{updateplayer=updateplayer->next;}
		}
	}
	switch(n)
	{
	case 1:
		{
			oneRow+=1;
			pos.X=2*WIDTH+11;
			pos.Y=12;
			SetConsoleCursorPosition(out,pos);
			cout<<oneRow;
			break;
		}
	case 2:
		{
			twoRow+=1;
			pos.X=2*WIDTH+11;
			pos.Y=13;
			SetConsoleCursorPosition(out,pos);
			cout<<twoRow;
			break;
		}
	case 3:
		{
			threeRow+=1;
			pos.X=2*WIDTH+11;
			pos.Y=14;
			SetConsoleCursorPosition(out,pos);
			cout<<threeRow;
			break;
		}
	case 4:
		{
			fourRow+=1;
			pos.X=2*WIDTH+11;
			pos.Y=15;
			SetConsoleCursorPosition(out,pos);
			cout<<fourRow;
			break;
		}
	default:
		cerr<<"error!"<<endl;
		system("pause");
	}
	pos.X=0;
	pos.Y=HEIGHT-3;
	SetConsoleCursorPosition(out,pos);
}
//������������
void Game::Save()
{
	fstream save("data.txt",ios_base::out|ios::binary);
	if(!save)
	{cerr<<"fail to open!"<<endl;system("pause");}
	else
	{
		save.write((char*)&playerlist.nodenumber,sizeof(unsigned int));
		Player* saveplayer=playerlist.head;
		for(unsigned int i=0;(i<playerlist.nodenumber)&&(saveplayer!=NULL);i++)
		{
			save.write((char*)saveplayer,sizeof(Player));
			saveplayer=saveplayer->next;
		}
		save.write((char*)&pause,sizeof(bool));
		if(pause==1)
		{
			save.write((char*)&currentScore,sizeof(unsigned int));
			save.write((char*)&oneRow,sizeof(unsigned int));
			save.write((char*)&twoRow,sizeof(unsigned int));
			save.write((char*)&threeRow,sizeof(unsigned int));
			save.write((char*)&fourRow,sizeof(unsigned int));
			save.write((char*)&level,sizeof(double));
			save.write((char*)&currentPlayer,sizeof(Player));
			save.write((char*)&fixedtable,sizeof(Table));
		}
		save.seekp(0,ios::beg);
		save.close();
//		cout<<"save.tiaoshi"<<endl;
	}
}
//����������ȡ����
void Game::Read()
{
	fstream read;
	read.open("data.txt",ios::in|ios::binary);
	if(!read)
	{cout<<"û�д����ļ����Ժ����ȫ����Ϸ"<<endl;}//system("pause");}
	else
	{
		read.seekg(0,ios::beg);
		read.read((char*)&playerlist.nodenumber,sizeof(unsigned int));
		if(playerlist.nodenumber>0)
		{
			playerlist.head=new Player;
			Player* readplayer=playerlist.head;
			read.read((char*)playerlist.head,sizeof(Player));
			for(unsigned int i=1;(i<playerlist.nodenumber);i++)
			{
				readplayer->next=new Player;
				read.read((char*)(readplayer->next),sizeof(Player));
				readplayer=readplayer->next;
			}
		}

		read.read((char*)&pause,sizeof(bool));
		if(pause==1)
		{
			read.read((char*)&currentScore,sizeof(unsigned int));
			read.read((char*)&oneRow,sizeof(unsigned int));
			read.read((char*)&twoRow,sizeof(unsigned int));
			read.read((char*)&threeRow,sizeof(unsigned int));
			read.read((char*)&fourRow,sizeof(unsigned int));
			read.read((char*)&level,sizeof(double));
			read.read((char*)&currentPlayer,sizeof(Player));
			read.read((char*)&fixedtable,sizeof(Table));
		}
		cout<<"��������ɹ������Ͽ�ʼ"<<endl;
//		system("pause");
	}	
	read.close();
}