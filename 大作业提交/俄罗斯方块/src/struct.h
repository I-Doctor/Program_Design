/*************************************************************************
    > File Name: struct.h
	> Orgnization:Tsinghua University
    > Author: �ӿ� 2015011158
    > Mail: ZK14115@163.com 
    > Created Time: 2016.7.7 ������
 ************************************************************************/
#pragma once
using namespace std;

enum Direction//�˶�����ö��
{
	LEFT =0,
	RIGHT =1,
	DOWN =2
};

enum State//����ö��
{
	NORTH =0,
	EAST =1,
	SOUTH =2,
	WEST =3
};

struct Position//��������
{
	int row;
	int column;
};
