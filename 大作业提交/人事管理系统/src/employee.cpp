#pragma once

#include"define.h"
#include"system.h"
#include"employee.h"

using namespace std;

int Employee::GetNumber(){return individualEmpNo;}

void Salesman::SetSaleAmount(double p)
{
	saleAmount=p;
}
void Salemanager::SetSaleAmount(System& sys)
{
	for(int i=0;i<5;i++)
	{
		if(no[i])
		{
			saleAmount+=(sys.Find(no[i])->GetSaleAmount());
		}
	}
}

bool Salemanager::SetNo(System& sys,int n1,int n2,int n3,int n4,int n5)
{
	if((n1==0||sys.Check(n1))&&n1>=0)
	{
		no[0]=n1;
	}
	else{return 0;}
	if((n2==0||sys.Check(n2))&&n2>=0)
	{
		no[1]=n2;
	}
	else{return 0;}
	if((n3==0||sys.Check(n3))&&n3>=0)
	{
		no[2]=n3;
	}
	else{return 0;}
	if((n4==0||sys.Check(n4))&&n4>=0)
	{
		no[3]=n4;
	}
	else{return 0;}
	if((n5==0||sys.Check(n5))&&n5>=0)
	{
		no[4]=n5;
	}
	else{return 0;}

	return 1;
}

void Manager::CalculatePay()
{
	accumPay=Managerbasic+grade*Managergrade;
};
void Technician::CalculatePay()
{
	accumPay=Technicianbasic+Technicianhour*(1+0.2*grade)*workHour;
}
void Salesman::CalculatePay()
{
	accumPay=Salesmanbasic+Salesmanamount*saleAmount;
}
void Salemanager::CalculatePay()
{
	accumPay=Managerbasic+Salemanagerrate*saleAmount;
}

ostream& operator <<(ostream& output,Manager& emp)
{
	output<<"编号："<<setw(4)<<left<<emp.individualEmpNo<<"岗位：";
	output<<setw(12)<<"MANAGER";
	output<<"级别："<<setw(4)<<emp.grade<<"工资："<<setw(7)<<emp.accumPay<<endl;
	return output;
}
ostream& operator <<(ostream& output,Technician& emp)
{
	output<<"编号："<<setw(4)<<left<<emp.individualEmpNo<<"岗位：";
	output<<setw(12)<<"TECHNICIAN";
	output<<"级别："<<setw(4)<<emp.grade<<"工资："<<setw(7)<<emp.accumPay<<"月工时："<<emp.workHour<<endl;
	return output;
}
ostream& operator <<(ostream& output,Salesman& emp)
{
	output<<"编号："<<setw(4)<<left<<emp.individualEmpNo<<"岗位：";
	output<<setw(12)<<"SALESMAN";
	output<<"级别："<<setw(4)<<emp.grade<<"工资："<<setw(7)<<emp.accumPay<<"销售额："<<emp.saleAmount<<endl;
	return output;
}
ostream& operator <<(ostream& output,Salemanager& emp)
{
	output<<"编号：";
	output<<setw(4)<<emp.individualEmpNo;
	output<<"岗位：";
	output<<setw(12)<<"SALEMANAGER";
	output<<"级别：";
	output<<setw(4)<<emp.grade;
	output<<"工资：";
	output<<setw(7)<<emp.accumPay;
	output<<"管辖：";
	output<<setw(4)<<emp.no[0]<<setw(4)<<emp.no[1]<<setw(4)<<emp.no[2]<<setw(4)<<emp.no[3]<<setw(4)<<emp.no[4];
	output<<endl;
	return output;
}

fstream& operator <<(fstream& fout,Manager& m)
{
	fout<<m.type<<" "<<m.type<<" "<<m.individualEmpNo<<" "<<m.grade<<" "<<m.accumPay<<endl;
	return fout;
}
fstream& operator <<(fstream& fout,Technician& t)
{
	fout<<t.type<<" "<<t.type<<" "<<t.individualEmpNo<<" "<<t.grade<<" "<<t.accumPay<<" "<<t.workHour<<endl;
	return fout;
}
fstream& operator <<(fstream& fout,Salesman& s)
{
	fout<<s.type<<" "<<s.type<<" "<<s.individualEmpNo<<" "<<s.grade<<" "<<s.accumPay<<" "<<s.saleAmount<<" "<<s.boss<<endl;
	return fout;
}
fstream& operator <<(fstream& fout,Salemanager& sm)
{
	fout<<sm.type<<" "<<sm.type<<" "<<sm.individualEmpNo<<" "<<sm.grade<<" "<<sm.accumPay<<" "<<sm.saleAmount;
	for(int i=0;i<5;i++)
	{
		fout<<" "<<sm.no[i];
	}
	fout<<endl;
	return fout;
}

fstream& operator >>(fstream& fin,Manager& m)
{
	fin>>m.type;
	fin>>m.individualEmpNo;
	fin>>m.grade;
	fin>>m.accumPay;
	return fin;
}
fstream& operator >>(fstream& fin,Technician& m)
{
	fin>>m.type;
	fin>>m.individualEmpNo;
	fin>>m.grade;
	fin>>m.accumPay;
	fin>>m.workHour;
	return fin;
}
fstream& operator >>(fstream& fin,Salesman& m)
{
	fin>>m.type;
	fin>>m.individualEmpNo;
	fin>>m.grade;
	fin>>m.accumPay;
	fin>>m.saleAmount;
	fin>>m.boss;
	return fin;
}
fstream& operator >>(fstream& fin,Salemanager& m)
{
	fin>>m.type;
	fin>>m.individualEmpNo;
	fin>>m.grade;
	fin>>m.accumPay;
	fin>>m.saleAmount;
	for(int i=0;i<5;i++)
	{
		fin>>m.no[i];
	}
	return fin;
}

bool Manager::In(System& sys)
{
	char g=1;
	cout<<"请输入級別（1-9）：        ";
	cin>>g;
	cin.clear(); 
	cin.sync(); 
	if(g-'0'>0&&g-'0'<10)
	{
		SetGrade(g-'0');
		return 1;
	}
	else
	{
		cout<<"输入错误";
		return 0;
	}	
}
bool Technician::In(System& sys)
{
	char g;
	cout<<"请输入級別（1-9）:         ";
	cin>>g;
	cin.clear(); 
	cin.sync(); 
	if(g-'0'>0&&g-'0'<10)
	{
		SetGrade(g-'0');
	}
	else
	{
		cout<<"输入错误";
		return 0;
	}	 
	cout<<"请输入月工作时长：  ";
	cin>>workHour;
	cin.clear(); 
	cin.sync(); 
//	emp.accumPay=emp.workTime*260;
	return 1;
}
bool Salesman::In(System& sys)
{
	char g;
	cout<<"请输入級別（1-9）:  ";
	cin>>g;
	cin.clear(); 
	cin.sync(); 
	if(g-'0'>0&&g-'0'<10)
	{
		SetGrade(g-'0');
	}
	else
	{
		cout<<"输入错误";
		return 0;
	}	 
	cout<<"请输入月销售额：    ";
	cin>>saleAmount;
	cin.clear(); 
	cin.sync(); 
	return 1;
}
bool Salemanager::In(System& sys)
{
	char g;
	int n1=0,n2=0,n3=0,n4=0,n5=0;
	cout<<"请输入級別（1-9）： ";
	cin>>g;
	cin.clear(); 
	cin.sync(); 
	if(g-'0'>0&&g-'0'<10)
	{
		SetGrade(g-'0');
	}
	else
	{
		cout<<"输入错误";
		return 0;
	}	
	cout<<"输入管辖销售员序号，0代表没有"<<endl;
	cout<<"销售员1： ";
	cin>>n1;
	cout<<"销售员2： ";
	cin>>n2;
	cout<<"销售员3： ";
	cin>>n3;
	cout<<"销售员4： ";
	cin>>n4;
	cout<<"销售员5： ";
	cin>>n5;
	if(SetNo(sys,n1,n2,n3,n4,n5))
	{return 1;}
	return 0;
}