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
	cout<<"****** 怀旧经典 老少皆宜 ******"<<endl;
	cout<<"-------------------------------"<<endl;
	cout<<"@@@@@@     俄罗斯方块    @@@@@@"<<endl;
	cout<<endl;
	cout<<"1、新游戏"<<'\t'<<"2、继续游戏"<<'\t'<<"3、排行榜"<<endl;
	cout<<"4、选择玩家"<<'\t'<<"5、控制说明"<<'\t'<<"6、退出游戏"<<endl;
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
		cout<<"选择玩家";
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