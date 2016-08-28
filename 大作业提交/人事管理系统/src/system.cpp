#pragma once

#include"system.h"

#include<iostream>
#include<fstream>
#include<conio.h>
#include<time.h>
#include<windows.h>

using namespace std;
//运行程序
void System::Run()
{
	/*
	Type t=(Type)0;
	ofstream file;
	file.open("data.txt",ios::app);
	if(!file)
	{
		file.open("data.txt",ios::out);
		file.write((char*)&t,sizeof(Type));
		file.close();
	}
	else{file.close();}
	*/
	while(1)
	{
		int choose=Welcome();
		switch(choose)
		{
		case 1:Input();break;
		case 2:Output();break;
		case 3:Change();break;
		case 4:Delete();break;
		case 5:system("cls");break;
		case 6:
			{
				clock_t start;
				start=clock();
				cout<<"BYE-BYE!";
				while(1)
				{
					if((clock()-start)>=(2*CLOCKS_PER_SEC))
					{break;}
				}
				return;
			}
		default:
			{
				clock_t start;
				start=clock();
				cout<<"输入错误，请重新输入";
				while(1)
				{
					if((clock()-start)>=(2*CLOCKS_PER_SEC))
					{break;}
				}
			}
		}
	}
}
//打印菜单，返回选择
int System::Welcome(void)
{
	int choose;
	for(int i=1;i<=5;i++)
	{
		cout<<setw(9-i)<<'*';
		for(int j=1;j<2*i-1;j++)
		{
			cout<<'*';
		}
		cout<<endl;
	}
	cout<<"-*-*公司人事管理系统*-*-"<<endl;
	cout<<"-*-*-*-*欢迎使用*-*-*-*-"<<endl;
	cout<<"***请输入序号选择功能***"<<endl;
	cout<<"【1】录入"<<"  【2】查询"<<'\n';
	cout<<"【3】修改"<<"  【4】删除"<<'\n';
	cout<<"【5】清屏"<<"  【6】退出   ";
	cin>>choose;
	return(choose);
}
// 录入c
void System::Input()
{
	int inputChoose;
	while(1)
	{
		cout<<"1.manager   2.technician   3.salesman   4.salemanager"<<endl;
		cout<<"输入0返回，1-4选择录入类型:"<<endl;
		cin>>inputChoose;
		if(inputChoose==0){break;}
		switch(inputChoose)
		{
		case 1:
			{
				currentEmp=&cm;
				Findno();
				cm.SetIndividualEmpNo(largestNumber++);
				cout<<largestNumber<<"号：";
				if(currentEmp->In(*this))
				{
					cout<<"确认？   1.是  2.否"<<endl;
					int confirm=0;
					cin>>confirm;
					if(confirm==1)
					{
						currentEmp->CalculatePay();
						Save(MANAGER);
					}
				}
				break;
			}
		case 2:
			{
				currentEmp=&ct;
				Findno();
				ct.SetIndividualEmpNo(largestNumber++);
				cout<<largestNumber<<"号：";
				if(currentEmp->In(*this))
				{
					cout<<"确认？   1.是  2.否"<<endl;
					int confirm=0;
					cin>>confirm;
					if(confirm==1)
					{
						currentEmp->CalculatePay();
						Save(TECHNICIAN);
//						delete currentEmp;
					}
				}
				break;
			}
		case 3:
			{
				currentEmp=&cs;
				Findno();
				cs.SetIndividualEmpNo(largestNumber++);
				cout<<largestNumber<<"号：";
				if(currentEmp->In(*this))
				{
					cout<<"确认？   1.是  2.否"<<endl;
					int confirm=0;
					cin>>confirm;
					if(confirm==1)
					{
						currentEmp->CalculatePay();
						Save(SALESMAN);
//						delete currentEmp;
					}
				}
				break;
			}
		case 4:
			{
				currentEmp=&csm;
				Findno();
				csm.SetIndividualEmpNo(largestNumber++);
				cout<<largestNumber<<"号：";
				if(currentEmp->In(*this))
				{
					cout<<"确认？   1.是  2.否"<<endl;
					int confirm=0;
					cin>>confirm;
					if(confirm==1)
					{
						csm.SetSaleAmount(*this);
						currentEmp->CalculatePay();
						Save(SALEMANAGER);
//						delete currentEmp;
					}
					
				}
				break;
			}
		default:
			{
				cout<<"输入错误，请重新输入"<<endl;
			}
		}
	}
}
//显示c
void System::Output()
{
	int outputChoose;
	cout<<"0.返回   1.显示全部   2.编号查询"<<endl;
	cout<<"输入编号选择"<<endl;
	cin>>outputChoose;
	switch(outputChoose)
	{
	case 0:break;
	case 1:ShowAll();break;
	case 2:Search();break;
	default:cout<<"输入错误";
	}
}
void System::ShowAll()
{
	fstream file;
	file.open("data.txt",ios::in);
	if(!file)
	{cout<<"沒有存檔"<<endl;}
	else
	{
		Type thisType;
		while(!file.eof())
		{
			bool f=file.eof();
			cout <<"FFF"<<f<<endl;
			thisType=Read(file);
			switch(thisType)
			{
			case 1:
				cout<<m;
				break;
			case 2:
				cout<<t;break;
			case 3:
				cout<<s;break;
			case 4:
				cout<<sm;break;
			}
		}
		file.close();
	}
	system("pause");
}
void System::Search()
{
}
//修改r
void System::Change()
{
	int changeChoose;
	cout<<"0.返回   1.选择全部   2.修改个人"<<endl;
	cout<<"输入编号选择"<<endl;
	cin>>changeChoose;
	switch(changeChoose)
	{
	case 0:break;
	case 1:
		{
			ChangeAll();
			break;
		}
	case 2:
		{
			SearchChange();
			break;
		}
	default:cout<<"输入错误，请重新输入"<<endl;
	}
}
void System::ChangeAll()
{
	char choose;
	cout<<"0.返回   1.全部升級   2.全部降級     ";
	cin>>choose;
	cin.clear(); 
	cin.sync(); 
	if(choose-'0'==0)
	{}
	else if(choose-'0'==1)
	{Promote(1);}
	else if(choose-'0'==2)
	{Promote(0);}
	else cout<<"輸入錯誤"<<endl;
}
void System::SearchChange()
{

}
void System::Promote(bool b)
{
	if(b)
	{
	}
	else
	{
	}
}
//删除r
void System::Delete()
{
	int deleteChoose;
	cout<<"0.返回   1.查找并删除   "<<endl;
	cout<<"输入编号选择"<<endl;
	cin>>deleteChoose;
	if(!deleteChoose){return;}
	if(deleteChoose==1)
	{
		SearchDelete();
	}
	else{cout<<"输入错误，请重新输入"<<endl;}
}
void System::SearchDelete()
{
}
//保存到最后
void System::Save(Type type)
{
	fstream file;
	file.open("data.txt",ios::app);
	if(!file)
	{cout<<"文件不存在，新建并保存"<<endl;
	file.open("data.txt",ios::out);}
	else{
	switch(type)
	{
	case MANAGER:
		file<<cm;break;
	case TECHNICIAN:
		file<<ct;
		break;
	case SALESMAN:
		file<<cs;
		break;
	case SALEMANAGER:
		file<<csm;
		break;
	default:cerr<<"type error!"<<endl;
	}
	file.close();
	}
}
//读一条到readEmp
Type System::Read(fstream& file)
{
	Type thisType;
	file>>thisType;
//	file.seekg(0-sizeof(Type),ios::cur);

//	file.read((char*)&thisType,sizeof(Type));
	
	switch(thisType)
	{
	case MANAGER:
			{
				if(readEmp!=NULL)
				{
//					delete readEmp;
				}
				readEmp=&m;
				file>>m;
				break;
			}
		case TECHNICIAN:
			{
				if(readEmp!=NULL)
				{
//					delete readEmp;
				}
				readEmp=&t;
				file>>t;
				break;
			}
		case SALESMAN:
			{
				if(readEmp!=NULL)
				{
//					delete readEmp;
				}
				readEmp=&s;
				file>>s;
				break;
			}
		case SALEMANAGER:
			{
				if(readEmp!=NULL)
				{
//					delete readEmp;
				}
				readEmp=&sm;
				file>>sm;
				break;
			}
	}
	return thisType;
}

Employee* System::Find(int n)
{
	fstream file;
	Type t;
	file.open("data.txt",ios::in);
	if(!file)
	{
		cerr<<"find open fail";
	}
	else
	{
		while(!file.eof())
		{
			t=Read(file);
			cout<<readEmp->GetNumber();
			if(readEmp->GetNumber()==n)
			{
				file.close();
				return readEmp;
			}
		}
	}
	return NULL;
}

bool System::Check(int n)
{
	fstream file;
	Type t;
	file.open("data.txt",ios::in);
	if(!file)
	{cerr<<"check open fail"<<endl;}
	while(!file.eof())
	{
		t=Read(file);
//		cout<<t<<endl;
		int ttt=readEmp->GetNumber();
		Type tttt=readEmp->type;
		if(readEmp->GetNumber()==n&&readEmp->type==3)
		{file.close();return 1;}
	}
	file.close();
	return 0;
}

void System::Findno()
{
	fstream f;
	char a[50];
	int n=0;
	f.open("data.txt",ios::in);
	if(!f)
	{
		largestNumber=0;
	}
	else
	{
		while(!f.eof())
		{	//bool b=f.eof();
			bool b=f.eof();
			f>>n;
			f>>n;
			f>>largestNumber;
			f.getline(a,sizeof(a));
		}
		f.close();
	}
}