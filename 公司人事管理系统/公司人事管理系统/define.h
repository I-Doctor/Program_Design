/*************************************************************************
    > File Name: define.h
	> Orgnization:Tsinghua University
    > Author: ÖÓ¿­ 2015011158
    > Mail: ZK14115@163.com 
    > Created Time: 2016.7.21 ÐÇÆÚËÄ
 ************************************************************************/
#pragma once
#include <fstream>

#define Managerbasic 10000
#define Managergrade 300
#define Technicianbasic 2000
#define Technicianhour 50 
#define Salesmanbasic 1000
#define Salesmanamount 0.1
#define Salemanagerrate 0.05

using namespace std;

enum Type
{
	MANAGER=1,
	TECHNICIAN=2,
	SALESMAN=3,
	SALEMANAGER=4
};

fstream& operator <<(fstream& fout,Type& type);
fstream& operator >>(fstream& fin,Type& type);