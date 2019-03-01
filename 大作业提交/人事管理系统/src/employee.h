#pragma once
#include"define.h"

#include<iostream>
#include<iomanip>
#include<fstream>

using namespace std;

class System;
class Employee
{
protected:
	int individualEmpNo;//±àºÅ
	int grade;
	double accumPay;
public:
	/*¹¹Ôìº¯Êý*/
	Type type;
	Employee()
	{
		type=(Type)0;
		individualEmpNo=0;
		grade=1;
		accumPay=0;
	}
	Employee(int g,double p)
	{
		grade=g;
		accumPay=p;
	}
	virtual ~Employee()	{}
	
	void SetGrade(int g){grade=g;}
	void SetAccumPay(double p){accumPay=p;}

	int GetNumber();
	double GetAccumpay(){return accumPay;}

	virtual void show(void)
	{
		cout<<setw(5)<<individualEmpNo;
		cout<<setw(5)<<grade;
		cout<<setw(10)<<accumPay<<endl;
	}
	virtual double GetSaleAmount(){return 0;};
	virtual bool In(System& sys){return 0;};

	friend ostream& operator <<(ostream&,Employee&);
	
	virtual void Change(){};

	void SetIndividualEmpNo(int n){individualEmpNo=n+1;}
	virtual void CalculatePay(){};
};

class Manager:virtual public Employee
{
public:
	Manager()
	{
		type=(Type)1;
	}
	~Manager(){};
	virtual void CalculatePay();
	bool In(System& sys);
	friend ostream& operator <<(ostream&,Manager&);
	friend fstream& operator <<(fstream& fout,Manager& m);
	friend fstream& operator >>(fstream& fout,Manager& m);
};

class Technician:public Employee
{
protected:
	int workHour;
public:
	Technician()
	{
		type=(Type)2;
	}
	~Technician(){};
	void CalculatePay();
	void SetWorkHour(int hour);
	bool In(System& sys);
	friend ostream& operator <<(ostream&,Technician&);
	friend fstream& operator <<(fstream&,Technician&);
	friend fstream& operator >>(fstream&,Technician&);
};

class Salesman:virtual public Employee
{
protected:
	double saleAmount;
	int boss;
public:
	Salesman()
	{
		boss=0;
		saleAmount=0;
		type=(Type)3;
	}
	~Salesman(){};
	virtual void CalculatePay();
	virtual void SetSaleAmount(double amount);
	double GetSaleAmount(){return saleAmount;}
	void SetBoss(int n);
	bool In(System& sys);
	friend ostream& operator <<(ostream&,Salesman&);
	friend fstream& operator <<(fstream&,Salesman&);
	friend fstream& operator >>(fstream&,Salesman&);
};

class Salemanager:public Manager ,public Salesman
{
protected:
	int no[5];
public:
	Salemanager()
	{
		no[0]=no[1]=no[2]=no[3]=no[4]=0;
		type=(Type)4;
	}
	~Salemanager(){}
	void CalculatePay();
	bool SetNo(System& sys,int n1,int n2,int n3,int n4,int n5);
	void SetSaleAmount(System& sys);
	bool In(System& sys);
	friend ostream& operator <<(ostream&,Salemanager&);
	friend fstream& operator <<(fstream&,Salemanager&);
	friend fstream& operator >>(fstream&,Salemanager&);
};

class Node
{
public:
	Employee* employee;
	Node* next;

	Node()
	{
		employee=NULL;
		next=NULL;
	}
};

class List
{
public:
	Node* head;

	List()
	{
		head=NULL;
	}
};
