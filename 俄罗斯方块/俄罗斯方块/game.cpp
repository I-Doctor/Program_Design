#include<iostream>
#include"game.h"
using namespace std;

void Game::Run()
{
	//Read();
	Welcome();
}

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

void Game::Welcome()
{
	PrintMenu();
	unsigned int menuChoice;
	cin>>menuChoice;
	switch(menuChoice)
	{
	case 1:{currentPlayer.score=0;Play();break;}
	case 2:Play();break;
	case 3:players.ShowList();break;
	case 4:{
		players.ShowList();
		cout<<"ѡ�����";
		unsigned int noPlayer;
		cin>>noPlayer;
		if(noPlayer>=1&&noPlayer<=playerNumber)
		{}
		else{cout<<"error!";}
		break;
		   }
	case 5:
	default:{
		//Save();
		cout<<"BYE-BYE!";}
	}
}

void Game::Play()
{
while(1)
{
	table0.Fresh();
//tiaoshi
//	system("pause");
}
}

void List::ShowList()
{
	cout<<"1";
}