#pragma once
#include<iostream>
#include"table.h"
using namespace std;

class Player//����࣬����ڵ㣬���������Ϣ
{
public:
	char name[20];
	unsigned int score;
	Player * next;

	Player(){next=NULL;}
	void AddScore();//�ӷ֣���Ϸ�����е���
};

class List//���а�
{	
public:
	Player * head;
	unsigned int topScore;//��߷ּ�¼����Ϸ������Ƚ�ʱ�õ�

	List(){head=NULL;}
	void ShowList();//��ʾ���а񣬰���������̣�ѡ�����а�ѡ������

//	void Delete(Player* p);//ɾ�����ʱ����
//	void Insert(Player* p);//�½����ʱ����

};

class Game            //��Ϸ�࣬�����������
{
private:
	unsigned int playerNumber;
	Player currentPlayer;
	Table table0,table1;
	List players;           //���ڱ��������Ϣ

	void Read();//��ȡ�浵���ݣ������Ϣ����ͣ��Ϸ����ʼ����ʱ����
	void Save();//������Ϸ״̬����ͣ�ͽ������֣��������Ϣ���������˳�ʱ����
	void Welcome();//��ʾ���˵���ѡ�����½����޸Ĺ��ܣ���ʼ�������
	void Play();//��ʾ��Ϸ���棬��ʼ��Ϸ�����
	void ChoosePlayer();//ѡ�����
	void Pause();//��ͣ��ѡ�����������Ϸ״̬����ͣ�����
	void Output();//ˢ����Ϸ������

public:
	void Run();//������������
};