/*************************************************************************
    > File Name: define.cpp
	> Orgnization:Tsinghua University
    > Author: ÖÓ¿­ 2015011158
    > Mail: ZK14115@163.com 
    > Created Time: 2016.7.21 ÐÇÆÚËÄ
 ************************************************************************/
#pragma once
#include <fstream>
using namespace std;
enum Type
{
	MANAGER=1,
	TECHNICIAN=2,
	SALESMAN=3,
	SALEMANAGER=4
};
fstream& operator <<(fstream& fout,Type& type)
{
	fout<<(int)type;
	return fout;
}
fstream& operator >>(fstream& fin,Type& type)
{
	int t;
	fin>>t;
	type=(Type)t;
	return fin;
}
