#pragma once
#include"struct.h"
#include"shape.h"
#include"table.h"
#include"shape.h"

#include<iostream>
#include<windows.h>

using namespace std;
class Shape;

class Player//玩家类，链表节点，储存玩家信息
{
public:
	char name[10];
	unsigned int score;
	Player * next;

	Player()
	{
		score=0;
		name[0]='n';
		name[1]='o';
		name[2]=' ';
		name[3]='p';
		name[4]='l';
		name[5]='a';
		name[6]='y';
		name[7]='e';
		name[8]='r';
		name[10]=0;
		next=NULL;
	}
	void Update();//加分，游戏过程中调用
};

class List//排行榜
{	
public:
	Player * head;
	unsigned int topScore;//最高分记录，游戏结束后比较时用到
	unsigned int nodenumber;

	List()
	{
		topScore=0;
		nodenumber=0;
		head=NULL;
	}
	void ShowList();//显示排行榜，包含排序过程，选择排行榜选项后调用

//	void Delete(Player* p);//删除玩家时调用
//	void Insert(Player* p);//新建玩家时调用

};

class Game            //游戏类，主程序的载体
{
private:
	bool pause;
	unsigned int currentScore;
	Player currentPlayer;
	Table currenttable;
	Table fixedtable;
	Shape* currentshape;
	Shape* nextshape;
	Shape shapeForSave;

	List playerlist;           //用于保存排行信息

	void Read();//读取存档数据，玩家信息与暂停游戏，开始运行时调用
	void Save();//保存游戏状态（暂停和结束两种）、玩家信息，主界面退出时调用
	void Welcome();//显示主菜单和选项、玩家新建与修改功能，初始化后调用
	void PrintMenu();

		void NewGame();
		void Continue();
			void Play();//运行游戏逻辑，开始游戏后调用
				void AddScore();
				Shape* NewShape();
				void Screen();

		void RankList();
		void ChoosePlayer();//选择玩家
		void ShowOperations();

	bool Pause();//暂停后选项、包含保存游戏状态，暂停后调用
	void Fresh();//

public:
	Game()
	{
		pause=0;
		currentScore=0;
		currentshape=NULL;
	}
	void Run();//包含整个程序
};