#pragma once
#include<iostream>
#include"table.h"
using namespace std;

class Player//玩家类，链表节点，储存玩家信息
{
public:
	char name[20];
	unsigned int score;
	Player * next;

	Player(){next=NULL;}
	void AddScore();//加分，游戏过程中调用
};

class List//排行榜
{	
public:
	Player * head;
	unsigned int topScore;//最高分记录，游戏结束后比较时用到

	List(){head=NULL;}
	void ShowList();//显示排行榜，包含排序过程，选择排行榜选项后调用

//	void Delete(Player* p);//删除玩家时调用
//	void Insert(Player* p);//新建玩家时调用

};

class Game            //游戏类，主程序的载体
{
private:
	unsigned int playerNumber;
	Player currentPlayer;
	Table table0,table1;
	List players;           //用于保存玩家信息

	void Read();//读取存档数据，玩家信息与暂停游戏，开始运行时调用
	void Save();//保存游戏状态（暂停和结束两种）、玩家信息，主界面退出时调用
	void Welcome();//显示主菜单和选项、玩家新建与修改功能，初始化后调用
	void Play();//显示游戏界面，开始游戏后调用
	void ChoosePlayer();//选择玩家
	void Pause();//暂停后选项、包含保存游戏状态，暂停后调用
	void Output();//刷新游戏界面用

public:
	void Run();//包含整个程序
};