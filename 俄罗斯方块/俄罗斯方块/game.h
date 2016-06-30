#pragma once
#include<iostream>
#include"table.h"
#include"shape.h"
using namespace std;

class Player//����࣬����ڵ㣬���������Ϣ
{
public:
	char name[10];
	unsigned int score;
	Player * next;

	Player(){next=NULL;}
	void Update();//�ӷ֣���Ϸ�����е���
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
	void ShowList();//��ʾ���а񣬰���������̣�ѡ�����а�ѡ������

//	void Delete(Player* p);//ɾ�����ʱ����
//	void Insert(Player* p);//�½����ʱ����

};

class Game            //��Ϸ�࣬�����������
{
private:
	bool pause;
	unsigned int currentScore;
	Player currentPlayer;
	Table currenttable;
	Table fixedtable;
	Shape* currentshape;
	Shape shapeForSave;
	List playerlist;           //���ڱ���������Ϣ

	void Read();//��ȡ�浵���ݣ������Ϣ����ͣ��Ϸ����ʼ����ʱ����
	void Save();//������Ϸ״̬����ͣ�ͽ������֣��������Ϣ���������˳�ʱ����
	void Welcome();//��ʾ���˵���ѡ�����½����޸Ĺ��ܣ���ʼ�������
	
		void NewGame();
		void Continue();
			void Play();//������Ϸ�߼�����ʼ��Ϸ�����
				void AddScore();
				Shape* NewShape();

		void RankList();
		void ChoosePlayer();//ѡ�����
		void ShowOperations();

	void Pause();//��ͣ��ѡ�����������Ϸ״̬����ͣ�����
	void Fresh();//

public:
	Game()
	{
		pause=0;
		currentScore=0;
		currentshape=NULL;
	}
	void Run();//������������
};