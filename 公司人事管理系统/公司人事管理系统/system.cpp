/*************************************************************************
    > File Name: system.cpp
	> Orgnization:Tsinghua University
    > Author: �ӿ� 2015011158
    > Mail: ZK14115@163.com 
    > Created Time: 2016.7.21 ������
 ************************************************************************/
#pragma once
#include"system.h"
#include<iostream>
#include<fstream>
#include<conio.h>
#include<time.h>
#include<windows.h>
using namespace std;

//���г���
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
		Findno();
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
				cout<<"     BYE-BYE !";
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
				cout<<"�����������������";
				while(1)
				{
					if((clock()-start)>=(2*CLOCKS_PER_SEC))
					{break;}
				}
			}
		}
	}
}
//��ӡ�˵�������ѡ��
int System::Welcome(void)
{
	int choose;
	for(int m=1;m<=5;m++)
	{
		cout<<setw(9-m)<<setiosflags(ios::right)<<'*';
		for(int h=1;h<2*m-1;h++)
		{
			cout<<'*';
		}
		cout<<endl;
	}
	cout<<"-*-*��˾���¹���ϵͳ*-*-"<<endl;
	cout<<"-*-*-*-*��ӭʹ��*-*-*-*-"<<endl;
	cout<<"***���������ѡ����***"<<endl;
	cout<<"��1��¼��"<<"  ��2����ѯ"<<'\n';
	cout<<"��3���޸�"<<"  ��4��ɾ��"<<'\n';
	cout<<"��5������"<<"  ��6���˳�   ";
	cin>>choose;
	return(choose);
}

// ¼��ģ�飬�������Ϊc
void System::Input()
{
	int inputChoose;
	while(1)
	{
		cout<<"1.manager   2.technician   3.salesman   4.salemanager"<<endl;
		cout<<"����0���أ�1-4ѡ��¼������:"<<endl;
		cin>>inputChoose;
		if(inputChoose==0){break;}
		switch(inputChoose)
		{
		case 1:
			{
				currentEmp=&cm;
				Findno();
				cm.SetIndividualEmpNo(largestNumber++);
				cout<<largestNumber<<"�ţ�";
				if(currentEmp->In(*this))
				{
					cout<<"ȷ�ϣ�   1.��  2.��"<<endl;
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
				cout<<largestNumber<<"�ţ�";
				if(currentEmp->In(*this))
				{
					cout<<"ȷ�ϣ�   1.��  2.��"<<endl;
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
				cout<<largestNumber<<"�ţ�";
				if(currentEmp->In(*this))
				{
					cout<<"ȷ�ϣ�   1.��  2.��"<<endl;
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
				cout<<largestNumber<<"�ţ�";
				if(currentEmp->In(*this))
				{
					cout<<"ȷ�ϣ�   1.��  2.��"<<endl;
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
				cout<<"�����������������"<<endl;
			}
		}
	}
}
void System::Save(Type type)
{
	fstream file;
	file.open("data.txt",ios::in|ios::out);
	if(!file)
	{cout<<"�޴浵�����½�������"<<endl;
	file.open("data.txt",ios::out);}

	file.seekp(0,ios_base::end);
	switch(type)
	{
	case MANAGER:
		file<<cm;break;
	case TECHNICIAN:
		file<<ct;break;
	case SALESMAN:
		file<<cs;break;
	case SALEMANAGER:
		file<<csm;break;
	default:cerr<<"type error!"<<endl;
	}
	file.close();
}

//��ʾģ�飬�������Ϊc
void System::Output()
{
	int outputChoose;
	cout<<"0.����   1.��ʾȫ��   2.��Ų�ѯ"<<endl;
	cout<<"������ѡ��"<<endl;
	cin>>outputChoose;
	switch(outputChoose)
	{
	case 0:break;
	case 1:ShowAll();break;
	case 2:Search();break;
	default:cout<<"�������";
	}
}
void System::ShowAll()
{
	fstream file;
	file.open("data.txt",ios::in);
	if(!file)
	{cout<<"�]�д�n"<<endl;}
	else
	{
		Type thisType;
		while(!file.eof())
		{
			bool f=file.eof();
//			cout <<"FFF"<<f<<endl;
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
	cout<<"�������ţ�  ";
	int findnumber;
	fstream fsearch;
	fsearch.open("data.txt",ios::in);
	if(!fsearch)
	{cout<<"�]�д�n"<<endl;return;}
	Type findType;
	cin>>findnumber;
	while(!fsearch.eof())
	{
		bool f=fsearch.eof();
		findType=Read(fsearch);
	if(readEmp->GetNumber()==findnumber)
	{
		switch(findType)
		{
		case 1:
			cout<<m;break;
		case 2:
			cout<<t;break;
		case 3:
			cout<<s;break;
		case 4:
			cout<<sm;break;
		}
		fsearch.close();
		return;
	}
	}
	cout<<"û���ҵ���"<<endl;
}

//�޸�ģ�飬�������Ϊr
void System::Change()
{
	int changeChoose;
	cout<<"0.����   1.ѡ��ȫ��   2.�޸ĸ���"<<endl;
	cout<<"������ѡ��"<<endl;
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
	default:cout<<"�����������������"<<endl;
	}
}
void System::ChangeAll()
{
	char choose;
	cout<<"0.����   1.ȫ������   2.ȫ������     ";
	cin>>choose;
	cin.clear(); 
	cin.sync(); 
	if(choose-'0'==0)
	{}
	else if(choose-'0'==1)
	{Promote(1);}
	else if(choose-'0'==2)
	{Promote(0);}
	else cout<<"ݔ���e�`"<<endl;
}
void System::Promote(bool b)
{
	int change=0;
	if(b)
	{
		change=1;
	}
	else
	{
		change=-1;
	}
		fstream fchange;
		int pos;
		fchange.open("data.txt",ios::in | ios::out);
		Type tchange;
		while(!fchange.eof())
		{
			pos=(int)fchange.tellg();
			tchange=Read(fchange);
			switch(tchange)
			{
			case MANAGER:
				{
					m.SetGrade(m.GetGrade()+change);
					if(m.GetGrade()==0){m.SetGrade(1);}
					if(m.GetGrade()==10){m.SetGrade(9);}
					m.CalculatePay();
					fchange.seekp(pos);
					fchange<<m;
					break;
				}
			case TECHNICIAN:
				{
					t.SetGrade(t.GetGrade()+change);
					if(t.GetGrade()==0){t.SetGrade(1);}
					if(t.GetGrade()==10){t.SetGrade(9);}
					t.CalculatePay();
					fchange.seekp(pos);
					fchange<<t;
					break;
				}
			case SALESMAN:
				{
					s.SetGrade(s.GetGrade()+change);
					if(s.GetGrade()==0){s.SetGrade(1);}
					if(s.GetGrade()==10){s.SetGrade(9);}
					s.CalculatePay();
					fchange.seekp(pos);
					fchange<<s;
					break;
				}
			case SALEMANAGER:
				{
					sm.SetGrade(sm.GetGrade()+change);
					if(sm.GetGrade()==0){sm.SetGrade(1);}
					if(sm.GetGrade()==10){sm.SetGrade(9);}
					sm.CalculatePay();
					fchange.seekp(pos);
					fchange<<sm;
					break;
				}
			}
			
		}
		fchange.close();
		return;
}	
void System::SearchChange()
{
	cout<<"����Ҫ���ĵĺ��룺  ";
	int changeNumber;
	cin>>changeNumber;
	fstream fchange;
	int pos;
	fchange.open("data.txt",ios::in | ios::out);
	Type changetype;
	while(!fchange.eof())
	{
		bool f=fchange.eof();
		pos=(int)fchange.tellp();
		changetype=Read(fchange);
		if(readEmp->GetNumber()==changeNumber)
		{
			switch(changetype)
			{
			case MANAGER:
				cout<<m;break;
			case TECHNICIAN:
				cout<<t;break;
			case SALESMAN:
				cout<<s;break;
			case SALEMANAGER:
				cout<<sm;break;
			}
			cout<<"ȷ�ϸ��ģ�   0.����  1.����ְλ  2.����ְλ    ";
			int sure=0;
			bool reset=0;
			cin>>sure;
			if(sure!=0&&sure!=1&&sure!=2)
			{
				cout<<"�������";
				fchange.close();
				return;
			}
			if(sure==0)
			{fchange.close();return;}
			int inputChoose=0;
			if(sure==1)
			{
				cout<<"1.manager   2.technician   3.salesman   4.salemanager"<<endl;
				cout<<"����0���أ�1-4ѡ��¼������:"<<endl;
				cin>>inputChoose;
				//�ж��Ƿ���Ҫ�������۾����Լ���θ���
				if(readEmp->type==3&&inputChoose!=3)
				{
					Update(changeNumber);//����Ա��ɾ���������������۾���
				}
				if(readEmp->type==3&&inputChoose==3)
				{
					reset=1;//����Ա�����ģ�����flag�ȴ����ĺ�������۾���
				}
			}
			if(sure==2)
			{
				inputChoose=(int)readEmp->type;
				if(inputChoose==3)
				{
					reset=1;
				}
			}
			if(inputChoose==0){return;}
			switch(inputChoose)
			{
			case 1:
				{
					currentEmp=&cm;
					cm.SetIndividualEmpNo(changeNumber-1);
					if(currentEmp->In(*this))
					{
						cout<<"ȷ�ϣ�   1.��  2.��"<<endl;
						int confirm=0;
						cin>>confirm;
						if(confirm==1)
						{
							currentEmp->CalculatePay();
							fchange.seekp(pos);
							if(pos){fchange<<'\n';}
							fchange<<cm;
							fchange.close();
							return;
						}
					}
					break;
				}
			case 2:
				{
					currentEmp=&ct;
					ct.SetIndividualEmpNo(changeNumber-1);
					if(currentEmp->In(*this))
					{
						cout<<"ȷ�ϣ�   1.��  2.��"<<endl;
						int confirm=0;
						cin>>confirm;
						if(confirm==1)
						{
							currentEmp->CalculatePay();
							fchange.seekp(pos);
							if(pos){fchange<<'\n';}
							fchange<<ct;
							fchange.close();
							return;
						}
					}
					break;
				}
			case 3:
				{
					currentEmp=&cs;
					cs.SetIndividualEmpNo(changeNumber-1);
					if(currentEmp->In(*this))
					{
						cout<<"ȷ�ϣ�   1.��  2.��"<<endl;
						int confirm=0;
						cin>>confirm;
						if(confirm==1)
						{
							currentEmp->CalculatePay();
							fchange.seekp(pos);
							if(pos){fchange<<'\n';}
							fchange<<cs;
							fchange.close();

							if(reset)
							{
								Reset(changeNumber);//����Ա�����ģ��������۾���
							}

							return;
						}
					}
					break;
				}
			case 4:
				{
					currentEmp=&csm;
					csm.SetIndividualEmpNo(changeNumber-1);
					if(currentEmp->In(*this))
					{
						cout<<"ȷ�ϣ�   1.��  2.��"<<endl;
						int confirm=0;
						cin>>confirm;
						if(confirm==1)
						{
							csm.SetSaleAmount(*this);
							currentEmp->CalculatePay();
							fchange.seekp(pos);
							if(pos){fchange<<'\n';}
							fchange<<csm;
							fchange.close();
							return;
						}
					}
					break;
				}
		default:
			{
				cout<<"�����������������"<<endl;
				return;
			}
		}
	}
	}
	cout<<"û���ҵ���"<<endl;

}
void System::Reset(int n)
{
	fstream freset;
	int pos;
	Type resetType;
	freset.open("data.txt",ios::in|ios::out);
	while(!freset.eof())
	{
		pos=(int)freset.tellg();
		resetType=Read(freset);
		if(resetType==SALEMANAGER)
		{
			csm=sm;
			csm.Reset(n,*this);
			freset.seekp(pos);
			freset<<'\n';
			freset<<csm;
			freset.close();
		}
	}
}

//ɾ��ģ�飬�������Ϊr
void System::Delete()
{
	int deleteChoose;
	cout<<"0.����   1.���Ҳ�ɾ��   "<<endl;
	cout<<"������ѡ��"<<endl;
	cin>>deleteChoose;
	if(!deleteChoose){return;}
	if(deleteChoose==1)
	{
		SearchDelete();
	}
	else{cout<<"�����������������"<<endl;}
}
void System::SearchDelete()
{
	cout<<"������ɾ���ı��:  ";
	int deleteNumber;
	cin>>deleteNumber;

	fstream fdelete;
	int pos;
	fdelete.open("data.txt",ios::in | ios::out);
	Type deletetype;
	while(!fdelete.eof())
	{
		bool f=fdelete.eof();
		pos=(int)fdelete.tellp();
		deletetype=Read(fdelete);
		if(readEmp->GetNumber()==deleteNumber)
		{
			switch(deletetype)
			{
			case MANAGER:
				cout<<m;
				break;
			case TECHNICIAN:
				cout<<t;
				break;
			case SALESMAN:
				cout<<s;
				break;
			case SALEMANAGER:
				cout<<sm;
				break;
			}
			cout<<"ȷ����   0.����  1.ȷ��      ";
			int sure=0;
			cin>>sure;
			if(sure!=0&&sure!=1)
			{
				cout<<"�������";
				return;
			}
			if(sure==0)
			{return;}

			switch(deletetype)
			{
			case MANAGER:
				fdelete.seekp(pos);
				if(pos){fdelete<<'\n';}
				m.SetIndividualEmpNo(-1);
				fdelete<<m;
				fdelete.close();
				break;
			case TECHNICIAN:
				fdelete.seekp(pos);
				if(pos){fdelete<<'\n';}
				t.SetIndividualEmpNo(-1);
				fdelete<<t;
				fdelete.close();
				break;
			case SALESMAN:
				fdelete.seekp(pos);
				if(pos){fdelete<<'\n';}
				s.SetIndividualEmpNo(-1);
				fdelete<<s;
				fdelete.close();
//�������۾���				
				Update(deleteNumber);

				break;
			case SALEMANAGER:
				fdelete.seekp(pos);
				if(pos){fdelete<<'\n';}
				sm.SetIndividualEmpNo(-1);
				fdelete<<sm;
				fdelete.close();
				break;
			}
			
			return;
		}
	}
	cout<<"û���ҵ���"<<endl;
}
void System::Update(int n)
{
	fstream fupdate;
	int pos;
	Type updatetype;
	fupdate.open("data.txt",ios::in|ios::out);
	while(!fupdate.eof())
	{
		pos=(int)fupdate.tellg();
		updatetype=Read(fupdate);
		if(updatetype==SALEMANAGER)
		{
			csm=sm;
			csm.Update(n,*this);
			fupdate.seekp(pos);
			fupdate<<'\n';
			fupdate<<csm;
			fupdate.close();
		}
	}
}

//���ļ���һ���������¶�ȡ�������
Type System::Read(fstream& file)
{
	Type thisType;
	file>>thisType;
//	file.seekg(-1,ios::cur);

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
//�ҵ�ĳһ����
Employee* System::Find(int n)
{
	fstream file;
	Type ty;
	file.open("data.txt",ios::in);
	if(!file)
	{
		cerr<<"find open fail";
	}
	else
	{
		while(!file.eof())
		{
			ty=Read(file);
//			cout<<readEmp->GetNumber();
			if(readEmp->GetNumber()==n)
			{
				file.close();
				return readEmp;
			}
		}
	}
	return NULL;
}
//����Ƿ������Ϊ���۾����Ͻ
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
//�ҵ���Ӧ���벢����
void System::Findno()
{
	fstream f;
	char a[90];
	int test;
	int n=0;
	f.open("data.txt",ios::in);
	if(!f)
	{
		largestNumber=0;
	}
	else
	{
		while(!f.eof())
		{
			f>>n;
			f>>n;
			f>>test;
			if(test!=0){largestNumber=test;}
			f.getline(a,sizeof(a));
		}
		f.close();
	}
}