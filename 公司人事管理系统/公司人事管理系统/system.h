/*************************************************************************
    > File Name: system.h
	> Orgnization:Tsinghua University
    > Author: ÖÓ¿­ 2015011158
    > Mail: ZK14115@163.com 
    > Created Time: 2016.7.21 ÐÇÆÚËÄ
 ************************************************************************/
#pragma once
#include"employee.h"
#include<iostream>
using namespace std;

class System
{
protected:
	int largestNumber;
	Manager m,cm;
	Technician t,ct;
	Salesman s,cs;
	Salemanager sm,csm;
	Employee* currentEmp;
	Employee* readEmp;
	
public:
	System()
	{
		currentEmp=NULL;
		readEmp=NULL;
		largestNumber=0;
	}
	void Run();
	int Welcome();
	void Input();
		void Save(Type type);

	void Output();
		void ShowAll();
		void Search();

	void Change();
		void ChangeAll();
			void Promote(bool);
			Employee* Find(int);
			bool Check(int n);
		void SearchChange();
			void Reset(int n);

	void Delete();
		void SearchDelete();
			void Update(int n);

	Type Read(fstream& file);
	void Findno();
};