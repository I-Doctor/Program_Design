/*************************************************************************
    > File Name: game.h
	> Orgnization:Tsinghua University
    > Author: �ӿ� 2015011158
    > Mail: ZK14115@163.com 
    > Created Time: 2016.7.7 ������
 ************************************************************************/
#pragma once
#include"struct.h"
#include"shape.h"
#include"table.h"
#include"shape.h"

#include<iostream>
#include<windows.h>

using namespace std;
class Shape;

class Player//����࣬����ڵ㣬���������Ϣ
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
		name[10]='\0';
		next=NULL;
	}
	
};

class List//���а�
{	
public:
	Player * head;
	unsigned int topScore;//��߷ּ�¼����Ϸ������Ƚ�ʱ�õ�
	unsigned int nodenumber;

	List()
	{
		topScore=0;
		nodenumber=0;
		head=NULL;
	}
	void ShowList();//��ʾ�б�ѡ�����а�ѡ������

//	void Delete(Player* p);//ɾ�����ʱ����
//	void Insert(Player* p);//�½����ʱ����

};

class Game            //��Ϸ�࣬�����������
{
private:
	bool pause;
	double level;
	unsigned int currentScore;
	unsigned int oneRow;
	unsigned int twoRow;
	unsigned int threeRow;
	unsigned int fourRow;
	Player currentPlayer;
	Table currenttable;
	Table fixedtable;
	Shape* currentshape;
	Shape* nextshape;
//	Shape shapeForSave;

	List playerlist;           //����б�

	void Read();//��ȡ�浵���ݣ������Ϣ���Ƿ���ͣ��Ϸ����ʼ����ʱ����
	void Save();//������Ϸ״̬�������Ϣ���������˳�ʱ����
	void Welcome();//��ʾ���˵���ѡ�����½����޸Ĺ��ܣ���ʼ�������
	void PrintMenu();

		void NewGame();
		void Continue();
			void Play();//������Ϸ�߼�����ʼ��Ϸ�����
				void AddScore(const int& n);//�ӷ֣���Ϸ�����е���
				Shape* NewShape();
				void PrintScreen();

		void RankList();
		void ChoosePlayer();//ѡ�����
		void ShowOperations();

	bool Pause();//��ͣ��ѡ�����������Ϸ״̬����ͣ�����
	void Fresh();//

public:
	Game()
	{
		level=0.55;
		pause=0;
		currentScore=0;
		oneRow=0;
		twoRow=0;
		threeRow=0;
		fourRow=0;
		currentshape=NULL;
		nextshape=NULL;
	}
	void Run();//������������
};