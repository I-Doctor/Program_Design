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
	void Output();
		void ShowAll();
		void Search();
	void Change();
		void ChangeAll();
			void Promote(bool);
			Employee* Find(int);
			bool Check(int n);
		void SearchChange();

	void Delete();
		void SearchDelete();

	Type Read(fstream& file);
	void Save(Type type);
	void Findno();
};
